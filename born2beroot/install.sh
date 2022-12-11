#!/bin/bash
#
# description: Configure system with requirements
# secretkey: 12341234

MYUSER=edbander

# run as root
[ "$(id -u)" != "0" ] && {
  echo "Run script as root"
  exit
}
apt update -y
apt upgrade -y

groupadd user42
usermod -aG user42 ${MYUSER}

# install sudo and config
apt install sudo

cat << EOCAT
Warning!
You are use sudo command!
EOCAT > /etc/sudoers.d/.message

cat << EOCAT
#
# Default configuration for sudoers
#
Defaults      env_reset
Defaults      mail_badpass
Defaults      secure_path="/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin"
Defaults      log_host, log_year, logfile="/var/log/sudo.log"
Defaults      lecture_file="/etc/sudoers.d/message", lecture="always"
Defaults      badpass_message="bad password"
Defaults      passwd_tries=3
Defaults      insults
Defaults      log_input,log_output
Defaults      requiretty

@includedir /etc/sudoers.d
EOCAT > /etc/sudoers

cat << EOCAT
#
# Alias specification
#
EOCAT > /etc/sudoers.d/00-aliases

cat << EOCAT
#
# Allow members of groups
#
%sudo     ALL=(ALL:ALL) ALL
EOCAT > /etc/sudoers.d/00-allow-members-groups

echo "
#
# Allow command or script without password
#
$MYUSER   ALL=(ALL) NOPASSWD: /usr/local/bin/monitoring.sh
" > /etc/sudoers.d/00-allow-command

usermod -aG sudo ${MYUSER}
# end sudo install and configuration

# strong passwords
apt install libpam-pwquality

cat << EOCAT
#
# /etc/pam.d/common-password - password-related modules common to all services
#
password  requisite                   pam_pwquality.so retry=3 minlen=10 ucredit=-1 dcredit=-1 maxrepeat=3 reject_username difok=7 enforce_for_root
password	[success=1 default=ignore]	pam_unix.so obscure use_authtok try_first_pass yescrypt
password	requisite			pam_deny.so
password	required			pam_permit.so
password	optional	pam_gnome_keyring.so
EOCAT > /etc/pam.d/common-password

cat << EOCAT
MAIL_DIR        /var/mail
FAILLOG_ENAB		yes
LOG_UNKFAIL_ENAB	no
LOG_OK_LOGINS		no

SYSLOG_SU_ENAB		yes
SYSLOG_SG_ENAB		yes

FTMP_FILE	/var/log/btmp

SU_NAME		su

HUSHLOGIN_FILE	.hushlogin

ENV_SUPATH	PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin
ENV_PATH	PATH=/usr/local/bin:/usr/bin:/bin:/usr/local/games:/usr/games

TTYGROUP	tty
TTYPERM		0600

ERASECHAR	0177
KILLCHAR	025
UMASK		022

PASS_MAX_DAYS	30
PASS_MIN_DAYS	2
PASS_WARN_AGE	7

UID_MIN			 1000
UID_MAX			60000

GID_MIN			 1000
GID_MAX			60000

LOGIN_RETRIES		5
LOGIN_TIMEOUT		60

CHFN_RESTRICT		rwh

DEFAULT_HOME	yes
USERGROUPS_ENAB yes
ENCRYPT_METHOD SHA512
EOCAT > /etc/login.defs
# end strong passwords

# ssh services
cat << EOCAT
Include /etc/ssh/sshd_config.d/*.conf

Port 4242
#AddressFamily any
ListenAddress 0.0.0.0
#ListenAddress ::

#HostKey /etc/ssh/ssh_host_rsa_key
#HostKey /etc/ssh/ssh_host_ecdsa_key
#HostKey /etc/ssh/ssh_host_ed25519_key

# Ciphers and keying
#RekeyLimit default none

# Logging
SyslogFacility AUTH
LogLevel INFO

# Authentication:

LoginGraceTime 2m
PermitRootLogin no
StrictModes yes
MaxAuthTries 6
MaxSessions 10

#PubkeyAuthentication yes

# Expect .ssh/authorized_keys2 to be disregarded by default in future.
#AuthorizedKeysFile	.ssh/authorized_keys .ssh/authorized_keys2

#AuthorizedPrincipalsFile none

#AuthorizedKeysCommand none
#AuthorizedKeysCommandUser nobody

# To disable tunneled clear text passwords, change to no here!
PasswordAuthentication yes
PermitEmptyPasswords no

# Change to yes to enable challenge-response passwords (beware issues with
# some PAM modules and threads)
ChallengeResponseAuthentication no

UsePAM yes

AllowAgentForwarding no
AllowTcpForwarding no
X11Forwarding no
PrintMotd no

# no default banner path
#Banner none

# Allow client to pass locale environment variables
AcceptEnv LANG LC_*

# override default of no subsystems
Subsystem	sftp	/usr/lib/openssh/sftp-server

# Example of overriding settings on a per-user basis
#Match User anoncvs
#	X11Forwarding no
#	AllowTcpForwarding no
#	PermitTTY no
#	ForceCommand cvs server
EOCAT > /etc/ssh/sshd_config

# install apparmor
apt install apparmor apparmor-utils apparmor-profiles apparmor-profiles-extra

# Enable apparmor (debian)
mkdir -p /etc/default/grub.d/
echo 'GRUB_CMDLINE_LINUX_DEFAULT="$GRUB_CMDLINE_LINUX_DEFAULT apparmor=1 security=apparmor"' \
  | tee /etc/default/grub.d/apparmor.cfg
update-grub
echo "Y" > /sys/module/apparmor/parameters/enabled

aa-status

echo "*/10 * * * * /usr/local/bin/monitoring.sh" >> /var/spool/cron/crontabs/root
