## Cross compilation

Kudos to folks over at [Bootlin](https://bootlin.com/training/kernel/) for
making this available under Creative Commons BY-SA.

## Config

* set arch, i.e. `ARCH=arm`
* set `CROSS_COMPILE` prefix
* as make flags or exported
* CROSS_COMPILE=`ccache arm-linux-` for faster recompilation
* `CONFIG_LOCALVERSION=-my-subversion`

* `arch/<arch>/boot/Image` - uncompressed bootable image
* `arch/<arch>/boot/*Image*` - spcific compressed img format, i.e. zImage for ARM
* `arch/<arch>/boot/vmlinux` - raw uncompressed image in ELF, useful for debugging

## Modules

* Compiled with `make -C /lib/modules/$(uname -r)/build M=$PWD modules`.
* Functionalities can't be lkms when:
    * Used/present for booting
    * Use `initrd`
    * Implement support for disk file system

* `modules.alias` - udev aliases to devices specified in `<driver-name>_devices.c` TODO SPECIFY
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
make oldconfig

# compile
make

# installs for the host be default
# affected files:
    # /boot/vmlinuz-<version>, same as the one in arch/<arch>/boot
    # /boot/System.map-<version>, symbol addresses
    # /boot/config-<version>
sudo make install

# installs modules
sudo make modules_install
```

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

* phandle, `<&node1>` - points to another node
* `<1 3 4 5>` - a tuple containing four cells
* `Documentation/device-tree/bindings` 
* Device Tree Bindings → documents that each specify
how a piece of HW should be described
* DeviceTree Specifications → base Device Tree syntax +
  number of standard properties.
* `struct of_device_id[]` - list of supported `compatible` strings

## Device model

* Driver interfaces with:
  * a **framework** that exposes it to the hw in a generic way
  * a **bus infrastructure** that detects the hw and communicates w/ it.
* 3 main `struct`s:
    * `bus_type` - reps a particular bus type (USB, PCI, I2C)
    * `device_driver` (a clumsy inheritance for more specialized versions)
    * `device` - reps a device connected to a bus (more clumsy inheritance)
* these are kernel-only. in userspace, `sysfs`.
  * /sys/bus
  * /sys/devices
  * /sys/class


### Bus drivers

Responsible for: 
* basically a bunch of non-specialized stuff that device drivers are not.
* Registering the bus type (`struct bus_type`)
* Registration of adapter drivers
* (Possibly) able to detect the connected devices providing a
  communication mechanism with the devices
* Allowing the registration of device drivers
* Managing the devices TODO
* Matching the device drivers against the devices detected by the adapter
  drivers
* API to implement both adapter drivers and device drivers
* Defining driver and device specific structures, mainly struct usb_driver and
  struct usb_interface
    

* A controller is a hardware component responsible for managing the operation
  of a specific device. I.e. disk, USB or controller, etc.
* An adapter is a hardware or software component that allows two different
  systems or components to work together. 
  * if hardware, it may require a driver.


