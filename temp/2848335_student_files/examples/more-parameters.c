#include <linux/module.h>
#include <linux/sched.h>

MODULE_AUTHOR("K Computing Inc.");
MODULE_DESCRIPTION("A very simple loadable module that does almost nothing.");
static int number = 24601;
static int perm0_no_desc=1234;
static int perm0_with_desc=9876;

static char* word = "blueberry";

module_param(number,int,S_IRWXU);
MODULE_PARM_DESC(number,"A sample integer modifiable parameter");
module_param(word,charp,S_IRUGO);
MODULE_PARM_DESC(word,"A sample string modifiable parameter");
module_param(perm0_no_desc,int,0);
module_param(perm0_with_desc,int,0);
MODULE_PARM_DESC(perm0_with_desc,"A parameter with permission 0 and with this description");
int my_init_module(void)
{
	printk("number=%d, word=%s\n",number,word);
	return 0;
}

void my_cleanup_module(void)
{
	printk("The module is now unloaded\n");
}
module_init(my_init_module);
module_exit(my_cleanup_module);
MODULE_LICENSE("GPL");
