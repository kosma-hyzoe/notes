# [Advanced Linux: Linux Kernel](https://www.linkedin.com/learning/advanced-linux-the-linux-kernel-2)

Kernel is a program. It is loaded and run by a boot loader, usually GRUB. It
implements virtual file systems, most importantly proc, sys, and debugfs.
It is a gatekeeper, it enforces priviliges. It is modular.

##  Misc

* `sysctl -a` - display all kernel parameters

## Working with hardware

* `lshw`, `lspci`, `lsusb`, `lsblk`, `lscpu`
* `hdparm` - get/set hard disk parameters
* `setpci` - configure PCI devices

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

## Booting

* GRUB loads the kernel and initial RAM root filesystem, sets up kernel command.
* GRUB 1 had `grub.conf`.
* GRUB 2 has `/etc/default/grub`, `/etc/grub.d`
* Kernel ignores unrecognized arguments, they can be passed to other programs
this way.
* `rdinit` - "RAM disk" init.
* `kernel-parameters.txt`?
* `initrd` filesystem
* post-`initrd` init runs
* `/boot/initrd.img-$(uname -r)`

## LKM (loadable kernel modules)

* `.ko` - kernel object files, "modules", for dynamically adding kernel
    functionality. Stored in `/lib/modules`, which is indexed by `modprobe`.
* `lsmod` loads chronologically. FOR CHECKING IF LOADED AND USED BY STH ELSE.
* `modprobe` - loads a module and it's dependencies, uses dependency files under
* `depmod` - generates a module config file, `modules.dep`, for `modprobe`
* `insmod` - insert a module. returns when module initialization function.
    remove with `rmmod`.
returns. Used on `.ko` files.
`/lib/modules/VERSION`, preferable to insmod
* `modules.dep`
* `modinfo cifs | grep - description`

### Compiling

### Example module

```c
#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

int init_simple() { ... }
void cleanup_simple() { ... }

module_init(init_simple);
module_exit(cleanup_simple);
```

## Kernel source

* [BuildYourOwnKernel @ Ubuntu Wiki](https://wiki.ubuntu.com/Kernel/BuildYourOwnKernel)

### Downloading

* `apt install linux-source`
* `git clone https://git.launchpad.net/~ubuntu-kernel-stable/+git/$RELEASE_CODENAME`

### Navigation

* `make cscope && csope` - make and use cscope.
* `make tags  && vim -t printk`
    * `ctrl+]` / `ctrl+t` - go to tag declaration/move back

## Common dependencies

* tags: `apt install exuberant-ctags`

