///pgm1
#! /bin/bash
echo "OS and version, release date"
uname -a
echo
cat /etc/os-release
echo
echo "kernel version"
uname -r
echo
echo "Avaiolble shells"
cat /etc/shells
echo
echo "CPU INFORMATION"
cat /proc/cpuinfo
echo
echo "Memory Information"
cat /proc/meminfo
echo
echo "Hard disk information"
lsblk
echo
echo "File system(mounted)"
df -h
