# Boot the system

* TODO press e on startup for kernel params?

* BIOS (Basic I/O System) does a Power-on self test (POST) and loads up the
  bootloader.
     * With MBR, looks for the master boot record on drive's first 512 bytes. It
       contains code used to load some MBR specific program which finally loads
       the bootloader.
     * With GPT, UEFI ("Unified extensible firmware interface") is used.
* Kernel initializes devices, memory and `init` process

## Bootloader

* boots into an operating system
* in case of linux: select the kernel and modify params
* other bootloaders: LILO, efilinux, coreboot, SYSLINUX
* params:
    * initrd - initial RAM disk location
    * BOOT_IMAGE - where kernel image is located
    * root - location of root system
    * ro - mount filestystem in read-only mode
    * quiet - don't see messages during boot
    * splash - # TODO splash screen?

* initramfs - temporary root filesystem built into the kernel to load the
necessary drivers for the real root filesystem. this was previously handled by
`initrd` (initial ram disk)

# Common init systems

* Based: OpenRC, Runit, dinit
    * elogind?
* Outdated: Upstart, sysv
*
