# Linux Kernel

## Temp

* `|&` for piping 0 1 and 2
* `sysctl -a`

## Basics

* is a program
* loaded and run by a boot loader, usually GRUB
* virtual file system entries
    * proc
    * sys
    * debugfs
* is a gatekeeper, enforces priviliges
* is modular

## Hardware commands

* `lshw`, `lspci`, `lsusb`, `lsblk`, `lscpu`
* `hdparam`
* `inb` and `outb`?
* `setpci`

## System calls

* `/include/uapi/asm-generic/unistd.h`
* libc uses system calls in an architecture-dependent manner
* errors are signified with negative value returns. `errno` is set to
  `abs(return_value)`.
* `printk()`
* `dmesg`
* `tail -f /var/log/dmesg`
* `journalctl -t kernel`, has an `-f` flag as well

## Virtual filesystems

* `sysfs` - kernel object info, i.e. PCI device info, on `/sys`
* `/proc` - processes virtual filesystem
	* threads are stored in `/proc/$(PID)/task`
	* file descriptors in `/proc/$(PID)/fd`
* `/dev` - device
	* major numbers, minor numbers, and type (c, character or b, block)
* `tty`

## Booting

* GRUB loads the kernel and initial root filesystem, sets up kernel command.
* GRUB 1 had `grub.conf`.
* GRUB 2 has `/etc/default/grub`, `/etc/grub.d`
* GRUB Interactive
* Kernel ignores unrecognized arguments, they can be passed to other programs
this way.
* rdinit
* `kernel-parameters.txt`?
* `initrd` filesystem
* post-`initrd` init runs
* `/boot/initrd.img-$(uname -r)`
