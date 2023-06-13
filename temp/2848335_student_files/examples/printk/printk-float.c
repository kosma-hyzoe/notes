#include <linux/module.h>
int my_init_module(void)
{
        float x=1.1;
        int n=99,m=777;
	printk(KERN_EMERG "testing emergency\n");
	printk(KERN_ERR "testing err\n");
	printk(KERN_NOTICE "testing notice\n");
	printk(KERN_DEBUG "testing debug\n");
        printk("STARTING FLOATS\n");
        printk("using g: m=%d x=%g n=%d\n",m,x,n);
        printk("using f: m=%d x=%f n=%d\n",m,x,n);
        printk("using e: m=%d x=%e n=%d\n",m,x,n);
        printk("done with float\n\n");
	return 0;
}

void my_cleanup_module(void)
{
	printk("The module is now unloaded\n");
}
module_init(my_init_module);
module_exit(my_cleanup_module);
MODULE_LICENSE("GPL");
