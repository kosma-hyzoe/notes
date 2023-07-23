# MMU

* MMU checks the addresses in TLB (translation lookaside buffer), which is a
  part of it. If the address is not found, has insufficient perms, or is swapped
  out, we get a page fault.

* kernel logical addresses
	* kmalloc
	* pa are fixed offset
	* use fixed pa-va mappings
	* `__pa(x)`, `__va(x)`
* kernel virtualaddress
	* virtually contiguous, not physically contiguous
	* often used by big buffers
* user virtual addresses

* upper va's - kernel spaces (top 1gb on x86_32)
* lowers va's - user space
* in linux, block devices
