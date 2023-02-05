#!/bin/bash
#
# Installation packages in chroot environment
#

_FIREWALL_POLICY=("DROP" "DROP" "DROP")
_TCP_PORTS=("80" "443" "4242")
_UDP_PORTS=

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
        apparmor-utils \
        iptables \
        iptables-persistent \
        sudo \
        lvm2 \
        cryptsetup
    
    _set_crypttab
    _grub_install 
    
    _set_firewall
    
    # bonus
    ## I'm use docker container for deploy
    _setup_docker
}

_set_locales() {
    _apt_install locales
    sed -i -s 's/# es_ES.UTF-8 UTF-8/es_ES.UTF-8 UTF-8/g' /etc/locale.gen
    locale-gen
}

_set_crypttab() {
    local _uuid="$(blkid /dev/mapper/${_DISKMAP##*/}p5 | grep -Eo  'UUID=(\"[0-9a-fA-F-]+\") ')"
    echo "${_CRYPTMAP}  ${_uuid} none luks,discard" >> /etc/crypttab
}

_setup_docker() {
    apt_install curl gnupg lsb-release
    mkdir -p /etc/apt/keyrings
    curl -fsSL https://download.docker.com/linux/debian/gpg | gpg --dearmor -o /etc/apt/keyrings/docker.gpg
    echo \
"deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] https://download.docker.com/linux/debian \
$(lsb_release -cs) stable" | sudo tee /etc/apt/sources.list.d/docker.list > /dev/null

    apt_install docker-ce docker-ce-cli containerd.io docker-compose-plugin
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
    update-initramfs -u
    grub-mkconfig --output /boot/grub/grub.cfg
}

_set_firewall() {
    _set_iptables_flush
    _set_iptables_default_policy
    _set_iptables_input 
    _set_iptables_output

    iptables-save > /etc/iptables/rules.v4
}

_set_iptables_flush() {
    # Flush rules
    /sbin/iptables -F 
    /sbin/iptables -X
    /sbin/iptables -Z 

    # Flush nat rules
    /sbin/iptables -t nat -F
    /sbin/iptables -t nat -X
    /sbin/iptables -t nat -Z

    /sbin/iptables -t mangle -F
    /sbin/iptables -t mangle -X
    /sbin/iptables -t mangle -Z

    /sbin/iptables -t filter -F
    /sbin/iptables -t filter -X
    /sbin/iptables -t filter -Z    
}

_set_iptables_default_policy() {
    local _default_input=${_FIREWALL_POLICY[0]}
    local _default_output=${_FIREWALL_POLICY[1]}
    local _default_forward=${_FIREWALL_POLICY[2]}

    [ "${_default_input}"   == "" ] && local _default_input="DROP"
    [ "${_default_output}"  == "" ] && local _default_output="DROP"
    [ "${_default_forward}" == "" ] && local _default_forward="DROP"

    /sbin/iptables -P INPUT ${_default_input}
    /sbin/iptables -P OUTPUT ${_default_output}
    /sbin/iptables -P FORWARD ${_default_forward}

    # General filter for loopback
    /sbin/iptables -A INPUT -i lo -j ACCEPT
    /sbin/iptables -A OUTPUT -o lo -j ACCEPT
}

_set_iptables_input() {
    /sbin/iptables -A INPUT -m conntrack --ctstate ESTABLISHED,RELATED -j ACCEPT

    for _port in ${_TCP_PORTS[@]}; do 
        /sbin/iptables -A INPUT -p tcp --dport ${_port} -m conntrack --ctstate NEW,ESTABLISHED -j ACCEPT
    done
}

_set_iptables_output() {
    /sbin/iptables -A OUTPUT -m conntrack --ctstate NEW,ESTABLISHED -j ACCEPT
}
main