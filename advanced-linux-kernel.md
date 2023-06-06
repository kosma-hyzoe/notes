# [Advanced Linux: Linux Kernel](https://www.linkedin.com/learning/advanced-linux-the-linux-kernel-2)

## Temp

* SATA? IDE?
* `rdinit` and `init` kernel flags?
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
* `hdparm`
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
# * `tty`

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

<<<<<<< HEAD
## LKM
* `.ko` - dynamically add kernel functionality
=======
## LKM (loadable kernel modules)


* `.ko` - dynamically add kernel functionality TODO
>>>>>>> dbe88449660153651b66c5de84e08a5826d56432
* `/lib/modules`
* modprobe looks only under `/lib/modules/$(uname -r)`
* `lsmod` loads chronologically. FOR CHECKING IF LOADED AND USED BY STH ELSE.
* `rmmod`
* `modinfo`
* `depmod` - generates module config files for modprobe
<<<<<<< HEAD
* `insmod` - insert a module. returns when module initialization function used
on KO files.
=======
* `modprobe` - loads a module and it's dependencies, uses dependency files under
`/lib/modules/VERSION`, preferable to insmode
* `insmod` - insert a module. returns when module initialization function
>>>>>>> dbe88449660153651b66c5de84e08a5826d56432
returns
* `modules.dep`
* `modinfo cifs | grep - description`

### Compiling

`make -C /lib/modules/$(uname -r)/build M=$PWD "${modules}"`

Example module:


```c
// TODO no main?
#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

int init_simple() { ... }
void cleanup_simple() { ... }

module_init(init_simple);
module_exit(cleanup_simple);
```
