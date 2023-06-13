#include <linux/module.h>
#include <linux/sched.h>

static int errval = 0;

module_param(errval,int,S_IRWXU);
MODULE_PARM_DESC(errval,"Value to return from init function");
int my_init_module(void)
{
	printk("errval=%d\n",errval);
	return errval;
}

void my_cleanup_module(void)
{
	printk("The module is now unloaded\n");
}
module_init(my_init_module);
module_exit(my_cleanup_module);
MODULE_LICENSE("GPL");
