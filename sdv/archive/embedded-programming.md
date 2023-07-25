# Embedded programming

* # reg = <0x47000000 0xaa4200>; Address of the Kernel and size of Kernel image. To find out the size we can use 'printf "0x%x\n" $(stat -c %s build/Image)'
* newlib

## Questions

* Alu?
* EABI?
* SRAM
* MMU? Virtual memory?
* state machine?
* task switching: stack counter, link register and program counter
* special purpose program status registers, apsrc

## Examining binaries

* `hd`
* `readelf`
	* -h - header
	* -s - section
	* -n - notes
	* alternatively `elfutils`
* `objdump` - elf and object files
* `arm-none-eabi*`
	* nm
	* size

