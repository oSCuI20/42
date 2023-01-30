#!/bin/bash
#
# Install debian into img file
#
_HOSTNAME="rpiproxy"

_ROOT_DIRECTORY=
_MOUNT_PATH=
_USERNAME=
_PUBKEY=
_LOOP=

_DEBIAN_VERSION="bullseye"
_DEBIAN_ARCH="amd64"
_DEBIAN_URL="https://deb.debian.org/debian"

_IMG_FILENAME="./disk-${_DEBIAN_VERSION}-${_DEBIAN_ARCH}.img"
_IMG_SIZE="25G"
_PARTED_SCRIPT="
mklabel msdos
mkpart primary      fat32    1MiB        510MiB
mkpart extended              511MiB      100%
mkpart logical      ext4     512Mib      100%
set 1 boot on
"
_INITRAMFS=false

_CRYPT_NAME="lvm-crypto"
_LVM_GROUP="vg-crypt"
_LVM_LOGICAL_VOLUME=(
    "-L 10G -n lv--root ${_LVM_GROUP}"
    "-L 1G  -n lv--swap ${_LVM_GROUP}"
    "-L 3G  -n lv--home ${_LVM_GROUP}"
    "-L 3G  -n lv--var ${_LVM_GROUP}"
    "-L 1G  -n lv--srv ${_LVM_GROUP}"
    "-L 1G  -n lv--tmp ${_LVM_GROUP}"
    "-L 3G  -n lv--var-log ${_LVM_GROUP}"
)

main() {
    [ $(id -u) -ne 0 ] && {
        echo "this script should be run with root user"
        exit 1
    }

    parse_arguments "$@"

    _install
    _qemu_create_image || {
        echo "error build image"
        return 1
    }
    _build_filesystem || {
        echo "error build filesystem"
        return 1
    }

    _debootstrap

    _mount "--make-rslave --bind" /sys rootfs/sys
    _mount "--make-rslave --bind" /dev rootfs/dev
    _mount "-t proc" /proc rootfs/proc

    _provisioning
    _chroot_provisioning
    _chroot_clean_image
    _umount

    # convert raw image to qcow format
    # qemu-img convert ${_IMG_FILENAME} ${_IMG_FILENAME%%.*}.qcow -O qcow
}

_install() {  # requirements into docker file
    apt update -y
    apt install -y binfmt-support debootstrap qemu qemu-user-static qemu-system-arm qemu-utils parted kpartx lvm2 cryptsetup
}

_provisioning() {
    _set_apt_configuration
    _set_hostname
    _set_hosts
    _set_root_authentication
    _set_fstab

    ${_INITRAMFS} && {
        mkdir -p ${_MOUNT_PATH}/usr/share/initramfs-tools
        cp -r $(pwd)/initramfs/* ${_MOUNT_PATH}/usr/share/initramfs-tools/.
    }
}

_chroot_provisioning() {
    cp ${_ROOT_DIRECTORY}/auto-install.sh ${_MOUNT_PATH}/rootfs/tmp/auto-install.sh
    chmod +x ${_MOUNT_PATH}/rootfs/tmp/auto-install.sh

    _ADDUSER=${_USERNAME} _DISKMAP=${_LOOP} chroot ${_MOUNT_PATH}/rootfs /tmp/auto-install.sh

    cp -R ${_ROOT_DIRECTORY}/rootfs/* ${_MOUNT_PATH}/rootfs/.
}

_chroot_clean_image() {
    [ -n "${_MOUNT_PATH}" ] || {
        echo "err _MOUNT_PATH variable is null"
        exit
    }
    find ${_MOUNT_PATH}/var/lib/apt/lists -type f | xargs rm -f

    rm -rf ${_MOUNT_PATH}/var/log/journal/*

    rm -f ${_MOUNT_PATH}/var/cache/apt/*.bin
    rm -f ${_MOUNT_PATH}/var/log/*.log
    rm -f ${_MOUNT_PATH}/var/log/apt/*.log
    rm -f ${_MOUNT_PATH}/var/log/btmp
    rm -f ${_MOUNT_PATH}/var/log/dmesg
    rm -f ${_MOUNT_PATH}/var/log/faillog
    rm -f ${_MOUNT_PATH}/var/log/fsck/*
    rm -f ${_MOUNT_PATH}/var/log/lastlog
    rm -f ${_MOUNT_PATH}/var/log/wtmp
}

_qemu_create_image() {
    [ -f ${_IMG_FILENAME} ] && {
        echo "${_IMG_FILENAME} exists, do you want remote it?"
        echo "press enter for remove old file or CTRL+C for cancel"
        read
        _umount
        rm -Rf ${_IMG_FILENAME}
    }
    qemu-img create ${_IMG_FILENAME} ${_IMG_SIZE} || return 1  # stop scripts if image creation fails
}

_build_filesystem() {
    echo "Building filesystem"
    [ -f ${_IMG_FILENAME} ] || {
        echo "_build_filesystem '${_IMG_FILENAME}' not found"
        return 1
    }
    parted --script --align optimal ${_IMG_FILENAME} -- ${_PARTED_SCRIPT}

    echo "Loading loop disk"
    _LOOP=$(kpartx ${_IMG_FILENAME} | head -1 | awk -F' ' '{print $5}')
    kpartx -av ${_IMG_FILENAME} 

    [ -z "${_LOOP}" ] && {
        echo "failed, _LOOP kpartx can not get loop devices"
        return 1
    }
    
    mkfs.vfat -F 32 -n boot /dev/mapper/${_LOOP##*/}p1 || return 1

    cryptsetup luksFormat --type luks1 /dev/mapper/${_LOOP##*/}p5
    echo "DECRYPTED VOLUME /dev/mapper/${_LOOP##*/}p5"
    cryptsetup luksOpen /dev/mapper/${_LOOP##*/}p5 ${_CRYPT_NAME}

    {
        pvcreate /dev/mapper/${_CRYPT_NAME} || {
            echo "can not create a physical volumes"
            return 1
        }

        vgcreate "vg-crypt" /dev/mapper/${_CRYPT_NAME} || {
            echo "can not create a virtual volumes"
            return 1
        }

        for n in $(seq 0  $((${#_LVM_LOGICAL_VOLUME[@]} - 1))); do 
            local lvm_volume=$(echo ${_LVM_LOGICAL_VOLUME[$n]} | awk -F' ' '{print $4}')
            local _tag=${lvm_volume##*--}
            local _device="/dev/${_LVM_GROUP}/${lvm_volume}"
            lvcreate ${_LVM_LOGICAL_VOLUME[$n]}

            [ "${_tag}" == "swap" ] && {
                mkswap ${_device}
                continue 
            }
            mkfs.ext4 -F -L "${_tag}fs" ${_device} || return 1
            [ "${_tag}" == "root" ] && {
                _rootfs="${_tag}fs"
                _mount "-t ext4" ${_device} ${_rootfs} || return 1
                continue
            }

            _mount "-t ext4" ${_device} ${_rootfs}/${_tag/-/\/} || return 1
        done 
    }

    [ $? -ne 0 ] && { 
        echo "can not create lvm volumes"
        return 1
    }

    _mount "-t vfat" /dev/mapper/${_LOOP##*/}p1 rootfs/boot || return 1

    return 0
}

_mount() {
    local options="${1}"
    local disk="${2}"
    local path="${_MOUNT_PATH}/${3}"

    mkdir -vp ${path}

    mount ${options} ${disk} ${path}
    
    return $?
}

_umount() {
    sync
    umount "${_MOUNT_PATH}/rootfs/dev"
    umount "${_MOUNT_PATH}/rootfs/proc"
    umount "${_MOUNT_PATH}/rootfs/sys"
    umount -R "${_MOUNT_PATH}/rootfs"

    for n in $(seq 0  $((${#_LVM_LOGICAL_VOLUME[@]} - 1))); do 
        local lvm_volume=$(echo ${_LVM_LOGICAL_VOLUME[$n]} | awk -F' ' '{print $4}')
        lvchange -an /dev/${_LVM_GROUP}/${lvm_volume}
    done 

    cryptsetup luksClose /dev/mapper/${_CRYPT_NAME}

    kpartx -d ${_IMG_FILENAME}
}

_debootstrap() {
    debootstrap \
        --arch=${_DEBIAN_ARCH} \
        --foreign \
        ${_DEBIAN_VERSION} \
        ${_MOUNT_PATH}/rootfs \
        ${_DEBIAN_URL}

    mkdir -p ${_MOUNT_PATH}/rootfs/usr/bin
    cp /usr/bin/qemu-arm-static ${_MOUNT_PATH}/rootfs/usr/bin/.
    cat << EOF > ${_MOUNT_PATH}/rootfs/debootstrap/mirror
${_DEBIAN_URL}
EOF
    chroot ${_MOUNT_PATH}/rootfs /debootstrap/debootstrap --second-stage
}

_set_apt_configuration() {
    cat << EOF > ${_MOUNT_PATH}/rootfs/etc/apt/sources.list
deb http://deb.debian.org/debian/ ${_DEBIAN_VERSION} main contrib
deb http://security.debian.org/debian-security ${_DEBIAN_VERSION}-security main contrib
deb http://deb.debian.org/debian/ ${_DEBIAN_VERSION}-updates main contrib
EOF
}

_set_network_setup() {
    cat << EOF > ${_MOUNT_PATH}/rootfs/etc/network/interfaces
source /etc/network/interfaces.d/*

# The loopback network interface
auto lo
iface lo inet loopback

auto eth0
iface eth0 inet dhcp
EOF
}

_set_hostname() {
    cat << EOF > ${_MOUNT_PATH}/rootfs/etc/hostname
${_HOSTNAME}
EOF
}

_set_hosts() {
    cat << EOF > ${_MOUNT_PATH}/rootfs/etc/hosts
127.0.0.1 localhost ${_HOSTNAME}

::1     ip6-localhost ip6-loopback
fe00::0 ip6-localnet
ff02::1 ip6-allnodes
ff02::2 ip6-allrouters
ff02::3 ip6-allhosts
EOF
}

_set_fstab() {
    local _fstab="# <file system>\t\t\t<dir>\t\t\ttype\t\t\t<options>\t\t\t0\t\t\t0\n"
    for n in $(seq 0  $((${#_LVM_LOGICAL_VOLUME[@]} - 1))); do 
        local lvm_volume=$(echo ${_LVM_LOGICAL_VOLUME[$n]} | awk -F' ' '{print $4}')
        local _tag=${lvm_volume##*--}
        local _device="/dev/${_LVM_GROUP}/${lvm_volume}"
        local _uuid="$(lsblk ${_device} -o UUID | tail -1)"


        [ "${_tag}" == "swap" ] && {
            local _fstab="${_fstab}UUID=${_uuid}\t\t\tnone\t\t\tswap\t\t\tsw\t\t\t0\t\t\t0\n"
            continue 
        }
        
        [ "${_tag}" == "root" ] && {
            local _fstab="${_fstab}UUID=${_uuid}\t\t\t/\t\t\text4\t\t\terrors=remount-ro\t\t\t0\t\t\t1\n"
            continue
        }

        local _fstab="${_fstab}UUID=${_uuid}\t\t\t${_tag/-/\/}\t\t\text4\t\t\tdefaults\t\t\t0\t\t\t2\n"
    done 

    local _uuid="$(lsblk /dev/mapper/${_LOOP##*/}p1 -o UUID | tail -1)"
    local _fstab="${_fstab}UUID=${_uuid}\t\t\t/boot\t\t\tvfat\t\t\tumask=0077\t\t\t0\t\t\t1\n"

    echo -e "${_fstab}" > ${_MOUNT_PATH}/rootfs/etc/fstab
}

_set_root_authentication() {
    mkdir -p ${_MOUNT_PATH}/rootfs/root/.ssh
    chown root:root ${_MOUNT_PATH}/rootfs/root/.ssh
    chmod 700 ${_MOUNT_PATH}/rootfs/root/.ssh
    [ -f ${_PUBKEY} ] || {
        echo "${_PUBKEY} not found"
        return 1
    }
    cat ${_PUBKEY} > ${_MOUNT_PATH}/rootfs/root/.ssh/authorized_keys
    return $?
}


_usage() {
    cat << EOF
Options:
    --hostname hostname, default: ${_HOSTNAME}
    --deb-version codename of debian, default: ${_DEBIAN_VERSION}
    --deb-arch system architecture, default: ${_DEBIAN_ARCH}
    --deb-url URL to download packages, default: ${_DEBIAN_URL}
    --img-filename name or filepath of the image, default: ${_IMG_FILENAME}
    --img-size set size assign, example 8G, 128M, ..., default: ${_IMG_SIZE}
    --username adduser to operating system, required
    --pub-key pubkey-to-copy-into-authorized_keys, required
    --initramfs flag to copy initramfs configurations, this is an optional argument

Usage:
    ${0} --pub-key path/to/file.pub --openvpn-client path/to/client.ovpn
EOF
}

parse_arguments() {
    while [ $# -ge 1 ]; do
        key=${1/ /}

        if  [ "${key}" != "--initramfs" ]; then
            shift
            value=$1
        fi

        case ${key} in
            --help)
                _usage
                exit 0
                ;;
            --hostname)
                _HOSTNAME=${value}
                ;;
            --username)
                _USERNAME=${value}
                ;;
            --deb-version)
                _DEBIAN_VERSION=${value}
                ;;
            --dev-arch)
                _DEBIAN_ARCH=${value}
                ;;
            --deb-url)
                _DEBIAN_URL=${value}
                ;;
            --img-filename)
                _IMG_FILENAME=${value}
                ;;
            --img-size)
                _IMG_SIZE=${value}
                ;;
            --pub-key)
                _PUBKEY=${value}
                ;;
            --initramfs)
                _INITRAMFS=true
                ;;
            *)
                _usage
                echo
                echo "${key} not recognized"
                exit 1
                ;;
        esac

        shift
    done

    [ -z "${_PUBKEY}" ] && {
        echo "--pub-key argument is empty"
        exit 1
    }

    [ -z "${_USERNAME}" ] && {
        echo "--username argument is empty"
        exit 1
    }

    _ROOT_DIRECTORY="$(pwd)/$(dirname ${0})"
    _MOUNT_PATH="/mnt/${_DEBIAN_VERSION}-${_DEBIAN_ARCH}"
}

main "$@"