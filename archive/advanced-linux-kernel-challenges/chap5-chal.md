# Advanced Linux: The Linux Kernel - Chapter 5 Challenges

## 3

### In kernel root directory

.tmp_vmlinux.kallsyms2.o
System.map
Module.symvers
modules.builtin.modinfo
.missing-syscalls.d
.version
.vmlinux.cmd
.tmp_vmlinux.kallsyms3
vmlinux
vmlinux.o
.tmp_vmlinux.kallsyms3.o
.tmp_vmlinux.kallsyms2
.tmp_vmlinux.kallsyms3.S
.tmp_vmlinux.kallsyms2.S
modules.order
.tmp_System.map
modules.builtin


### In `arch/x86/boot/`

pm.o
.header.o.cmd
setup.elf
.bioscall.o.cmd
.cpuflags.o.cmd
.tty.o.cmd
.zoffset.h.cmd
zoffset.h
.cpustr.h.cmd
version.o
tty.o
.setup.bin.cmd
video-bios.o
a20.o
cpu.o
mkcpustr
edd.o
cmdline.o
.video.o.cmd
.cmdline.o.cmd
.setup.elf.cmd
.edd.o.cmd
.voffset.h.cmd
bzImage
.memory.o.cmd
video-mode.o
printf.o
.cpu.o.cmd
cpucheck.o
early_serial_console.o
.main.o.cmd
.video-vga.o.cmd
.version.o.cmd
main.o
.video-bios.o.cmd
cpustr.h
video-vga.o
video.o
regs.o
.cpucheck.o.cmd
cpuflags.o
video-vesa.o
vmlinux.bin
.printf.o.cmd
.pmjump.o.cmd
pmjump.o
string.o
copy.o
.video-mode.o.cmd
voffset.h
.video-vesa.o.cmd
.vmlinux.bin.cmd
.bzImage.cmd
.string.o.cmd
.early_serial_console.o.cmd
.regs.o.cmd
bioscall.o
.mkcpustr.cmd
.pm.o.cmd
memory.o
header.o
.copy.o.cmd
.a20.o.cmd
setup.bin

### Note

There might be an extra file here or there cause I accidentally overwritten
a file with these files thru cat after make modules, install_modules and
install. I decided not to redo the process cause it already took me longer than
it should.

For the record, I used:
`find -maxdepth 1 -newer NEWER -type f  >NEW_FILES`

and then:
`cd arch/x86/boot && find -maxdepth 1 -newer ~/linux-5.4.0/NEWER -type f >> ~/linux-5.4.0/NEW_FILES`


