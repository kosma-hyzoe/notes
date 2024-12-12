


## DT props

* `#adress-cells` - numbers of cells needed to carry the address
* `#size-cells`
  * 0 - one address
  * 1 - address range
  * 2 - multiple address ranges
* size cells, size x
* aliases
* look for freq in i2c
* `/sys/firmware/devicetree/base/model`
* `make dtbs_check`
* `simple-bus` - bus where all sub-nodes are memory mapped
* fully generic -  dt schema repo
* subsystem specific - dt schema repo + `Documentation/device-tree/bindings`
*

* kernel provides portable, arch and hw independent api, handles concurrency
* proc - operating system related (processes, memory man, parameters)
* sys - tree of devices, hardware representation
* kernel to userspace api/abi is stable (so that we can update the kernel)
  * /proc and /sys contents shouldn't change, only extend
* internal kernel api/abi(modules) is not stable

## Dependencies

* `ncpus * 2` !!
* `b depends on a` - b not visible until a enabled
* `a select b ` - select b is a is selected
* `make oldconfig` - update to newer kernel (xconfig silently sets default for
  new stuff, oldconfig prompts)

## Build

* `.../boot/Image` - uncompressed
* `.../boot/*Image*` - self-decompressing kernel
* `/boot/System.map*` - symbols for debugging purposes
* `modules.alias`
* `scripts/diffconfig`
   * plug in device
   * bus driver sends MODALIAS string, decoded by udev
     * vendor, product id, device id, additional characteristic
   * `kmod` will load the appropriate module based on modules.alias(compiled by `make modules_install`)
   * in kernel driver, all supported devices should be listed (`MODULE_DEVICE_TABLE()`)

## Misc

* `sudo exportfs -rv`
## uboot

* `env default -f -a`
* `saveenv`
* `dm tree`

* `echo `"<n>Debug info" > /dev/ksmg`
* `admin-guide/kernel-parameters`
* vendor forks - good for PoCs, bad for other stuff
* `git clone --refrence=` ?
* some stuff can be built with Clang
* oops messages only on illegal memory accesses
* fixed stack size
* gpl v3 is gpl v2 rewritten by lawyers for lawyers
* you should mainline your drivers!
* scripts/get_maintainer.pl
* defconifg - only diffs from defaults

## Extra session

* ctags

