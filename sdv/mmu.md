# MMU

* MMU checks the addresses in TLP (translation lookaside buffer), which is a
  part of it. If the address is not found, has insufficient perms, or is swapped
  out, we get a page fault.

* kernel logical addresses
	* kmalloc
	* pa are fixed offset
	* use fixed pa-va mappings
* kernel virtualaddress
	* virtually contiguous, not physically contiguous
	* often used by big buffers
* user virtual addresses

