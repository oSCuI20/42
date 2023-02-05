#!/bin/bash
#
# System monitoring
#

function main() {
  wall "
    #Architecture: $(uname -a)
    #CPU physical: $(cpu)
    #vCPU: $(vcpu)
    #Memory Usage: $(usedram)/$(freeram) ($(usageram))
    #Disk Usage: $(useddisk)/$(totaldisk) ($(usagedisk))
    #CPU load: $(usagecpu)
    #Last boot: $(lastboot)
    #LVM use: $(lvmisused)
    #Connections TCP: $(connestablished) ESTABLISHED
    #User log: $(nusers)
    #Network: IP $(netinfo)
    #Sudo: $(nsudocmds) cmd"
}

function cpu() {
  grep 'physical id' /proc/cpuinfo | uniq | wc -l | tr -d '\n'
}

function vcpu() {
  grep 'processor' /proc/cpuinfo | wc -l | tr -d '\n'
}

function usagecpu() {
  top -bn1 | grep '^%Cpu' | cut -c 9- | xargs | awk '{printf("%.1f%%"), $1 + $3}'
}

function freeram() {
  free -m | awk '$1 == "Mem:" {printf("%sMB"), $2}'
}

function usedram() {
  free -m | awk '$1 == "Mem:" {printf("%s"), $3}'
}

function usageram() {
  free | awk '$1 == "Mem:" {printf("%.2f%%"), $3/$2*100}'
}

function totaldisk() {
  df -BG | grep '^/dev/' | grep -v '/boot$' | awk '{disk += $2} END {printf("%sGB"), disk}'
}

function useddisk() {
  df -BG | grep '^/dev/' | grep -v '/boot$' | awk '{disk += $3} END {printf("%s"), disk}'
}

function usagedisk() {
  df -BM | grep '^/dev/' | grep -v '/boot$' | awk '{usage += $3} {total += $2} END {printf("%d%%"), usage/total*100}'
}

function lastboot() {
  who -b | awk '$1 == "system" {print $3 " " $4}'
}

function lvmisused() {
  [ $(lsblk | grep "lvm" | wc -l) -gt 0 ] && {
    echo -n "yes"
    return
  }
  echo -n "no"
}

function connestablished() {
  n=$(ss -neopt state established | wc -l)
  n=$(($n - 1))
  echo -n ${n}
}

function nusers() {
  users | wc -w | tr -d '\n'
}

function nsudocmds() {
  journalctl _COMM=sudo | grep COMMAND | wc -l | tr -d '\n'
}

function netinfo() {
  declare -a IPS
  declare -a MASK

  for iface in $(ls /sys/class/net); do
    [ "${iface}" == "lo" ] && {
      continue
    }
    IP=$(ip addr show ${iface} | awk '$1 == "inet" {printf("%s", $2)}' | egrep -o "[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}")
    [ "${IP}" == "" ] && {
      continue
    }
    IPS=(${IPS[@]} ${IP})
    MASK=(${MASK[@]} "$(cat /sys/class/net/${iface}/address)")
  done
  echo -n "${IPS[@]} (${MASK[@]})"
}


main
