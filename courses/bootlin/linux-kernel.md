## Cross compilation

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

* `modules.alias` - udev aliases to devices specified in `<driver-name>_devices.c`

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
