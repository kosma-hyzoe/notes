# Linux Kernel

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
* `/dev` - device files
	* major numbers, minor numbers, and type (c, character or b, block)
* `tty`
