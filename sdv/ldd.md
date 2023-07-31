* mechanism: what capabilites
* policy: how can those caps be used
* drivers can be loadable kernel modules!
* modules can utilize software drivers along device drivers, i.e filesystems

* Unix transfers control from user to kernel space on interrupts and sys calls
* sys calls are process related, interrupts aren't
* kernel space has a small stack
* `sys_` for sys calls functions

* `EXPORT_SYMBOL(name)` / `EXPORT_SYMBOL_GPL(name)`
* kernel can make use of facility immiediately after registration

* `cat /proc/sys/kernel/printk`
	* current
	* default for non-explicit messages
	* min. allowed level
	* boot-time default log level
	* can simply `cat 8 >` to set current and ignore others
