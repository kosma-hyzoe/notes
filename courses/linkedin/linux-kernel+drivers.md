# [Advanced Linux: Linux Kernel](https://www.linkedin.com/learning/advanced-linux-the-linux-kernel-2)

Also features some notes from course "Linux Device Drivers"

## General info

Kernel is a program. It is loaded and run by a boot loader, usually GRUB. It
implements virtual file systems, most importantly proc, sys, and debugfs.
It is a gatekeeper, it enforces priviliges. It is modular.

`sysctl -a` - display all kernel parameters

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

### Common dependencies

* tags: `apt install exuberant-ctags`

## Debug file system

* `Documentation/filesystems/debugfs`
* `cpuwalk.bt`
* `bpftrace`, `crash` (on crash dumps or `/proc/kcore`)

```bash
cat /sys/kernel/debug/tracing/available_tracers

cd /sys/kernel/debug
echo 0 > tracing_on # disable t
echo function_graph >  current_tracer
echo > trace # empty the trace file
echo ":mod:e1000e" > set_ftrace_filter
echo 1 > tracing_on
sleep 1
echo 0 > tracing_on
cat trace > /tmp/t

cd /sys/kernel/debug/tracing
echo :mod:multifile > set_ftrace_filter
echo > trace
echo 1 > tracing_on
insmod /tmp/mymodule.ko
cat trace

cd /lib/modules/$(uname -r)/build
crash vmlinux/proc/kcore
```

## [IOSchedulers](https://wiki.ubuntu.com/Kernel/Reference/IOSchedulers)

```
cat /sys/block/loop1/queue/scheduler
echo mq-deadline !$
```

## The `/dev` directory

* a ram-based temp system
* create block or char device: `mknod device_name b minor_number major_number`
* removable drives should be mounted, not used as device files

## Drivers

* useful to use `umask` / `umask 0` when creating drivers.
* most driver functions are executed in process context in privileged kernel
    mode.
* `copy_to_user()`, `copy_from_user()`

## Block devies

* TODO Caching?
* TODO IO scheduling?
* TODO request queue?
* loop devices - mages mounted inside existing filestysyems (i.e. `/dev/loop0`)
* Network block device (NBD)
* Minor number usually tells you which device and partition
* mounting - associating a filesystem with a dir in the system file system(sic!)
* `struct gendisk`, `block_device_operations`, `sd_ioctl()` , `ioctl()`

## Network drivers

* have no device files
* handles transmit requests from the kernel and receive request from the
    outside world.
* `ifconfig`, `ip`, `/proc/net`
* `strace -e socket ip addr >/dev/null`
* `cat /proc/net/dev`
* `ethtool -i eno1` - what driver is associated
* TODO netlink sockets
* TODO `/proc/interrupts`
