#include <linux/module.h>
int my_init_module(void)
{
	printk(KERN_EMERG "testing emergency\n");
	printk(KERN_ERR "testing err\n");
	printk(KERN_NOTICE "testing notice\n");
	printk(KERN_DEBUG "testing debug\n");
	return 0;
}

void my_cleanup_module(void)
{
	printk("The module is now unloaded\n");
}
module_init(my_init_module);
module_exit(my_cleanup_module);
MODULE_LICENSE("GPL");
