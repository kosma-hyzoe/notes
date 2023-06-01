# Chapter 1 Challenges

1. `6.2.6-76060206-generic` (`uname -r`)
2. 13843936 bytes, or around 14MB (`ls -l /boot/vmlinuz($uname -r)`)
3. 326941664 bytes, or around 31GB (`free -h`)
4. 9 calls to mmap (`strace -c date`)
5. `chdir()`. (runned a bash script with plain `cd` only and then grep'd
  `strace ./cd.sh |& grep "/$(echo ~)`)
6. around 355 (`grep -c "#define __NR" /usr/src/linux-headers-$(uname -r)/include/uapi/asm-generic/unistd.h`)
  minus 2 for `#ifndef __SYSCALL`(...)
7. stdin, stdout and stderr (`ls /proc/$(pidof sleep)/fd`)
8. Yup. `(lscpi | grep "PCI")`
9. 1. (`cat /proc/sys/net/ipv4/ip_forward`)
10. Yeah.
  * Also yeah cause `ls -l /dev/sda* | wc -l` > 1.
  * 15: `strace fdisk -l |& grep sys/dev/block | grep openat | wc -l`
11. Yeah. (`dmesg | grep -i "command"`). Also yeah: `/var/log/auth.log`.
12. 8. (`ls -l | grep "^c" | grep " 1," | wc -l`)
