# MMU

* MMU checks the addresses in TLB (translation lookaside buffer), which is a
  part of it. If the address is not found, has insufficient perms, or is swapped
  out, we get a page fault.
* DMA?
* `nmap()` syscall allows the userspace to request a specific va
* lazy allocation - allocate only once process actually needs the memory,
  not upon request. optimizes stuff

* kernel logical addresses
	* kmalloc
	* pa are fixed offset
	* use fixed pa-va mappings
	* `__pa(x)`, `__va(x)`
* kernel virtualaddress
	* virtually contiguous, not physically contiguous
	* often used by big buffers
* user virtual addresses
	* makes full use of the MMU

* upper va's - kernel spaces (top 1gb on x86_32)
* lowers va's - user space
* in linux, block devices
* kernel address above CONFIG_PAGE_OFFSET, on ARM it's 0x8000_0000_0000
