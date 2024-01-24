## Debugging

* sudo mount -t debugfs none /sys/kernel/debug
    * https://www.kernel.org/doc/html/latest/filesystems/debugfs.html

## Essential settings

* CONFIG_KALLSYMS_ALL - oops messages with symbols
* CONFIG_DRIVER_DEBUG?
* CONFIG_DEBUG_INFO

## Magic SysRq
* Allows to run multiple debug / rescue commands even when the kernel seems to
be in deep trouble
    * On PC: press [Alt] + [Prnt Scrn] + <character> simultaneously
    ([SysRq] = [Alt] + [Prnt Scrn])
    * On embedded: in the console, send a break character
(Picocom: press [Ctrl] + a followed by [Ctrl] + \ ), then press <character>
* Example commands:
    * h: show available commands
    * s: sync all mounted filesystems
    * b: reboot the system
    * n: makes RT processes nice-able.
    * w: shows the kernel stack of all sleeping processes
    * t: shows the kernel stack of all running processes
    * You can even register your own!

## KGDB

* CONFIG_KGDB, CONFIG_GDB_SCRIPTS
    * https://www.kernel.org/doc/html/latest/dev-tools/gdb-kernel-debugging.html

## JTAG

* There's a immediately GDB interface ready JTAG and an OpenOCD one:
    * gdb -> openocd -> JTAG -> ARM
    * on ARM CONFIG_DEBUG_LL and CONFIG_EARLYPRINTK + `earlyprintk` command line arg
      for when something is broken before tty layer
    * on non-ARM, SERIAL_EARLYCON

## Power
