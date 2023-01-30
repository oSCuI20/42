#!/bin/bash
#
# Installation packages in chroot environment
#

main() {
    [ -z "${_DISKMAP}" ] && {
        echo "$0 failed"
    }

    _adduser

    _set_locales
    _apt_upgrade

    _apt_install \
        linux-image-amd64 \
        ca-certificates \
        net-tools \
        ntp \
        openssh-server \
        binutils \
        isc-dhcp-client \
        lvm2 \
        cryptsetup
    
    _grub_install 
    _systemd_enabled sshd ntp
}

_set_locales() {
    _apt_install locales
    sed -i -s 's/# es_ES.UTF-8 UTF-8/es_ES.UTF-8 UTF-8/g' /etc/locale.gen
    locale-gen
}

_adduser() {
    [ -z "${_ADDUSER}" ] && {
        echo "can not add a user, global _ADDUSER variable is empty"
        return 1
    }

    useradd -s /bin/bash -d /home/${_ADDUSER} -G sudo ${_ADDUSER}
    yes ${_ADDUSER}-password | passwd ${_ADDUSER}
}

_apt_upgrade() {
    apt update -y
    apt upgrade -y
}

_apt_install() {
    apt update -y
    apt install -y ${@}
}

_systemd_enabled() {
    systemctl enable ${@}
}

_grub_install() {
    _apt_install grub-common grub2-common grub-pc grub-pc-bin
    grub-install --boot-directory /boot ${_DISKMAP}
    mv /etc/grub.d/30_os-prober /root/.
    grub-mkconfig --output /boot/grub/grub.cfg
}

main