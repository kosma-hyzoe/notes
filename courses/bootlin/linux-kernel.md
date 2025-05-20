# Linux Device Drivers

* `kmalloc` - fixed offset, kernel logical addresses
* `vmalloc`
  * not physically contiguos
  * not suitable for DMA

## Debug

* `dev_err_ratelimited()` - print up to x times based on burst values, then stop
* `#define DEBUG` or `ccflags-$(CONFIG_DRIVER) += DDEBUG`
* `CONFIG_DYNAMIC_DEBUG` - can be enabled/disabled:
  * per file
  * per module
  * per message
  * per line

## DMA

* coherent mapping - more expensive, but less hassle with cache handling.
  * we need a virt address for CPU and another one for controller in case
    there is IO-MMU in between
  * typically allocated once and used for enitre
* streaming buffer - uses another buffer, i.e. user buffer

* `dma-mapping` - maps buffers at physical addresses. enough for external devices
* `dmaengine` - abstracts controllers (start/stop transfer, queue, configure)
*

## IO mem

* `request_mem_region`/`release_mem_region`
* `proc/iomem`
* `read[b/w/l/q]` - `byte/word/long/q`
* `devmem2`

## Misc

* don't use device managed alloc when mem is used outside device node
* `errno`
* each process has 1/4 mem allocated for kernel, rest for userpace, by MMU
* string compare for compatible strings are expensive, so if we need slightly
  different behavior for different devices, we use `.data` field in `of_device_id`
* uboot: `dm tree`
* vendor forks - good for PoCs, bad for other stuff
* gpl v3 is gpl v2 rewritten by lawyers for lawyers
* `scripts/get_maintainer.pl`
* `dtc -I fs /sys/firmware/devicetree/base`

## The Linux Kernel

* kernel provides portable, arch and hw independent api, handles concurrency
* `/proc` - operating system related (processes, memory man, parameters)
* `/sys` - tree of devices, hardware representation
* kernel to userspace api/abi is stable (so that we can update the kernel)
* `/proc` and `/sys` contents shouldn't change, only extend
* internal kernel API/ABI(modules) is not stable

## Cross compilation

## Config

* `b depends on a` - b not visible until a enabled
* `a select b ` - select b is a is selected
* `scripts/diffconfig`
* set arch, i.e. `ARCH=arm`
* set `CROSS_COMPILE` prefix
* as make flags or exported
* CROSS_COMPILE=`ccache arm-linux-` for faster recompilation
* `CONFIG_LOCALVERSION=-my-subversion`

* `arch/<arch>/boot/Image` - uncompressed bootable image
* `arch/<arch>/boot/*Image*` - self-decompressing img format, i.e. zImage for ARM
* `arch/<arch>/boot/vmlinux` - raw uncompressed image in ELF, useful for debugging
* `/boot/System.map*` - symbols for debugging purposes

## Modules

* Compiled with `make -C /lib/modules/$(uname -r)/build M=$PWD modules`.
* Functionalities can't be lkms when:
    * Used/present for booting
    * Use `initrd`
    * Implement support for disk file system

* `lsmod` loads chronologically. FOR CHECKING IF LOADED AND/OR USED BY STH ELSE.
    * equivalent of `cat /proc/modules`
* `modinfo <module_name>` for modules in `/lib/modules`
* `modinfo some_module.ko` - find available parameters
* `modinfo other_module_in_lib_modules | grep - description`
   * `vermagic` - kernel parametes required for inserting
* `modprobe -r` - remove with dependencies
* you can set default parameters in `/etc/modprobe.conf` or `/etc/modprobe.d/`
* you can set parameters in the kernel command line
* `echo 0 > /sys/module/<module_name>/parameters/<param_name>` -
  edit params during runtime

## Compilation

```bash
# optional, useful for upgrading .config from an eariler release
# or after editing .config manually
# will prompt for new stuff!
make oldconfig

# compile
make

# installs for the host be default
# affected files:
    # /boot/vmlinuz-<version>, same as the one in arch/<arch>/boot
    # /boot/System.map-<version>, symbol addresses for debugging
    # /boot/config-<version>
sudo make install

# installs modules
sudo make modules_install
``

## Boot

* `bootz <zImage address> - <dtb address>` - `-` for  no initramfs
* in uboot, `bootargs` hold the kernel command line


## Modules

* Code marked as `__init` - Removed/freed (TODO) after initialization
 (static kernel or module.)
* Code marked as `__exit` - Discarded when module compiled statically into the
  kernel, or when module unloading support is not enabled.
* Two macros are used in the kernel to export functions and variables:
    * EXPORT_SYMBOL(symbolname), which exports a function or variable to all modules
    * EXPORT_SYMBOL_GPL(symbolname), which exports a function or variable only to GPL
    * used to identify the proprietary fuckery
* to compile, needs access to kernel headers:
    * Full kernel sources (configured + `make modules_prepare`)
    * Only kernel headers (`linux-headers-*` packages in Debian/Ubuntu
      distributions, or directory created by `make headers_install`).

* For built-in modules:  `Add a line in the Makefile file based on the Kconfig
  setting: obj-$(CONFIG_USB_SERIAL_NAVMAN) += navman.o`

Single-file out of tree module makefile:

```make
ifneq ($(KERNELRELEASE),)
obj-m := hello.o
else
KDIR := /path/to/kernel/sources
all:
<tab>$(MAKE) -C $(KDIR) M=$$PWD
endif
```

## Device tree

* `of_` (open firmware) functions usually read the device trees
* `/sys/firmware/devicetree/base/model` - get the device name :p
* fully generic -  dt schema repo
* subsystem specific - dt schema repo + `Documentation/device-tree/bindings`
* `simple-bus` - bus where all sub-nodes are memory mapped
* `make dtbs_check`
* TODO dirs, what-is-where
* `Documentation/device-tree/bindings`
* Device Tree Bindings → documents that each specify
how a piece of HW should be described
* DeviceTree Specifications → base Device Tree syntax +
  number of standard properties.
* `struct of_device_id[]` - list of supported `compatible` strings

* `#adress-cells` - numbers of cells needed to carry the address
* `#size-cells`
  * 0 - one address
  * 1 - address range
  * 2 - multiple address ranges

## Device model

Types of devices:
* Network (`ip a`)
* Block (`/dev`)
* Character (`/dev`)
  * `struct file_operations` - open, close, r/w, ioctl
  * `struct file`
    * `void *private_data`
    * the user buffer cannot be dereferenced
    * use `get_user`, `put_user`, `copy_to_user`, `copy_from_user` instead
* Internal sysfs devices (`pinctrl`, IIO)

* 3 main `struct`s:
    * `bus_type` - reps a particular bus type (USB, PCI, I2C)
    * `device_driver` (software!)
    * `device` - reps hardware to given bus, handled by given driver
      (sometimes has a slightly different name, i.e. `usb_interface`)
    * uses inheritance to create specialized `device_driver` and `device`
      structs for each subsystem
* for a USB-ethernet connector:
  * usb bus
  * ethernet usb device driver driver
  * "TP-LINK FOOUSB adapter" device
  * ethernet framework
* in code, `module_init` simply registers the created `struct device`

### How (some) devices are identified

* device is plugged in
* bus driver sends MODALIAS string, decoded by udev
  (vendor, product id, device id, additional characteristic)
* `kmod` will load the appropriate module based on `modules.alias`
  (compiled by `make modules_install`)
* in driver, the alias is created by (`MODULE_DEVICE_TABLE()`)
* when there is a match between the alias and driver's `MODULE_DEVICE_TABLE`,
  the core/bus driver **probes** the device, the `probe` function is called for each device

### USB example

The core driver (`drivers/usb/core`) talks to:
*
* USB device drivers (everywhere depending on class, i.e. `drivers/net/usb`)
* adapter drivers (`drivers/usb/host`), i.e. USB2.0 (`dwc2`) and USB3.0 (`dwc3`)
  * they report IDs that aliases are based to identify the device driver and
    adapter driver needed
  * host controller(hardware components that interface between the bus and the
    system) drivers are implemented as parts of adapter drivers, expose
    generic bus functionality
```
PCI adapter -> PCI Core -> PCI Dev. Driver + USB Adapter Driver -> USB Core
```

* these are kernel-only. in userspace, `sysfs`.
  * /sys/bus
  * /sys/devices
  * `/sys/class` - i.e. `net`, `input`, `block`
  * used by `udev`



## Kernel frameworks for device drivers

* `devtmps` TODO
* `get_user(v, p)`, `put_user(v, p)`
* `nmap()` zero copy (no buffer)
* `devm_kmalloc`
* `/sys/class`


## Input subsysterm

* app -> syscall interface -> char driver api -> **input subsystem** -> drivers
* events composed by `input_event()`, sent by `input_sync()`.
* polled periodically, no support for interrupts

## Kernel Memory

* virtual mem: top quarter is kernel space, the lower part is
  exclusive for each process
* `CONFIG_VMSPLIT_2G` etc. on 32bit systems
* after loading program to RAM, additional mappings can be made:
  * mem allocations
  * mem mapped files
  * `mmap'ed areas
* user mem is allowed to over-commit memory, preventable with
  `/proc/sys/vm/overcommmit_*`. OOM kills some processes then.
* `kmalloc (slab caches) vs vmalloc(non-physically contiguous)? TODO
* CMA, contihuous memory allocator, for reserving memory at boot
* `GFP_KERNEL` - standard mem alloc, may block
* `GFP_ATOMIC` - code not allowed to block, i.e. irq or critical sections
* `SLABs` are multiplied caches(objects) of fixed, small size(i.e. 512-1024 bytes)
  for some of the kernel data
  structures. SLAB, SLOB and SLUB are slightly different, SLUB is now standard.
* `kmalloc`
  * depends on slabs for small allocations, pages for larger ones
  * the standard kernel alloc
  * `kzalloc` - zero-initialized
  * `kcalloc` - kzalloc for n-element arrays
  * `krealloc` - reallocates, can resize
  * `kfree`
  * all have `devm_` equivalents!

### Kernel mem debugging

* KASAN (Kernel Address Sanitizer)
  * Dynamic memory error detector, to find use-after-free and out-of-bounds bugs.
  * Available on most architectures
  * See dev-tools/kasan for details.
* KFENCE (Kernel Electric Fence)
  * A low overhead alternative to KASAN, trading performance for precision. Meant to
  be used in production systems.
  * Only available on x86, arm64 and powerpc (Linux 5.13 status)
  * See dev-tools/kfence for details.
* Kmemleak
  * Dynamic checker for memory leaks
  * This feature is available for all architectures.
  * See dev-tools/kmemleak for details
* to access I/O memory as virtual addresses, you need `ioremap()`, preferably
  `devm_ioremap()`

### ?

* `platform_get_resource(pdev, ..)` - retrieve a device physical address or IRQ from the dt.


### Process, thread, task

* forked processes are concurrent and isolated (separate memeory)
* threads are concurrent, but use the same address space
* process is made using `fork()`. consists of:
  * an address space containing program code, data, stack, etc.
  * a single thread known by the scheduler
* more threads can be made using `pthread_create()`. they will run in the same
address space.
* ...so threads are a subset of forks in a way?
* each thread has an associated `struct task_struct`.
* interrupt context/process context
* to sleep, must declare a wait queue, which will be used to store the list of
  threads waiting for an even

## Interrupts

* use `devm_request_irq()` in `probe()`
* interrupt handlers don't handle sleep!
* Interrupt handlers are run with all interrupts disabled on the local CPU (see
https://lwn.net/Articles/380931).

* "wake_up() / wake_up_interruptible() wakes up all non-exclusive tasks and only
one exclusive task"
* wake_up_all() / wake_up_interruptible_all() wakes up all non-exclusive and all
exclusive tasks

* `void wait_event(queue, condition);`
    * Sleeps until the task is woken up and the given C expression is true.
* `int wait_event_killable(queue, condition);`
    * Can be interrupted, but only by a fatal signal (SIGKILL). Returns -ERESTARTSYS if
      interrupted.
* `int wait_event_interruptible(queue, condition);`
    * Can be interrupted by any signal. Returns -ERESTARTSYS if interrupted.
* int wait_event_timeout(queue, condition, timeout);
    * Also stops sleeping when the task is woken up or the timeout expired (a timer is
      used).
    * Returns 0 if the timeout elapsed, non-zero if the condition was met.
* int wait_event_interruptible_timeout(queue, condition, timeout);
    * Same as above, interruptible.
    * Returns 0 if the timeout elapsed, -ERESTARTSYS if interrupted, positive value if the
      condition was met.
* `wait_for_completion()` - no condition, adds add the end(?) of wait queue
* cat /sys/kernel/debug/irq/irqs/


## Debug

* sudo mount -t debugfs none /sys/kernel/debug
    * https://www.kernel.org/doc/html/latest/filesystems/debugfs.html
* `print_hex_dump_debug()`
* `dev_printk.h` - `pr_` equivalent when integrated with the linux device model
    * %p: Display the hashed value of pointer by default.
    * %px: Always display the address of a pointer (use carefully on non-sensitive
    addresses).
    * %pK: Display hashed pointer value, zeros or the pointer address depending on
    kptr_restrict sysctl value.
    * %pOF: Device-tree node format specifier.
    * %pr: Resource structure format specifier.
    * %pa: Physical address display (work on all architectures 32/64 bits)
    * %pe: Error pointer (displays the string corresponding to the error number)
* `CONFIG_DYNAMIC_DEBUG`
* the `loglevel=` kernel param
*  `/proc/sys/kernel/printk`, more [here](https://www.kernel.org/doc/html/latest/admin-guide/sysctl/kernel.html)
*  `CONFIG_DEBUG_FS`

### Essential settings

* CONFIG_KALLSYMS_ALL - oops messages with symbols
* CONFIG_DRIVER_DEBUG?
* CONFIG_DEBUG_INFO

### Magic SysRq
* Allows to run multiple debug / rescue commands even when the kernel seems to
be in deep trouble
    * On PC: press `[Alt]` + `[Prnt Scrn]` + `<character>` simultaneously
    (`[SysRq]` = `[Alt]` + `[Prnt Scrn]`)
    * On embedded: in the console, send a break character
(Picocom: press `[Ctrl]` + a followed by `[Ctrl]` + \ ), then press `<character>`
* Example commands:
    * h: show available commands
    * s: sync all mounted filesystems
    * b: reboot the system
    * n: makes RT processes nice-able.
    * w: shows the kernel stack of all sleeping processes
    * t: shows the kernel stack of all running processes
    * You can even register your own!

### KGDB

* CONFIG_KGDB, CONFIG_GDB_SCRIPTS
    * https://www.kernel.org/doc/html/latest/dev-tools/gdb-kernel-debugging.html

### JTAG

* There's a immediately GDB interface ready JTAG and an OpenOCD one:
    * gdb -> openocd -> JTAG -> ARM
    * on ARM CONFIG_DEBUG_LL and CONFIG_EARLYPRINTK + `earlyprintk` command line arg
      for when something is broken before tty layer
    * on non-ARM, SERIAL_EARLYCON

## Delete me :')

### I2C

* Adapter (master, controller, bus :') )
    * initiates transactions
    * usually one
    * no address
* Client (slave, device)
    * responds to transactions
    * many per bus
    * 7 bit address in hardware
