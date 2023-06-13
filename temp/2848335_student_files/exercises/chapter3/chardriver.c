#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/poll.h>
#include <linux/fs.h>
#include <linux/cdev.h>
#include <linux/mm.h>


/* Defaults */
#define DEFAULT_MAJOR	168
#define DEFAULT_DEBUG	1
#define DEFAULT_NAME	"chardriver"

/* Parameters that can be set by insmod */
static int major = 	DEFAULT_MAJOR;
static int debug =	DEFAULT_DEBUG;
static char* name = 	DEFAULT_NAME;

/* Allow insmod to change these parameters. Include documentation. */
module_param(major,int,S_IRUGO	);
MODULE_PARM_DESC(major,	"Used to override driver's major number");

module_param(debug,int,S_IRUGO);
MODULE_PARM_DESC(debug,	"Set to 1 for debugging output, 0 for no output");

module_param(name,charp,S_IRUGO);
MODULE_PARM_DESC(name,	"The name of the character driver");

MODULE_AUTHOR(		"You Are");
MODULE_DESCRIPTION(	"This a a very simple character driver");


/* Function Prototypes */
ssize_t chardriver_read (struct file *, char *, size_t, loff_t *);
ssize_t chardriver_write (struct file *, const char *, size_t, loff_t *);

/*
 * This must be made static since it is use after the current
 * function returns. It holds the methods used by the driver.
 */
#define NUMMINORS 5
static struct file_operations chardriver_fops = {
    .read = chardriver_read,
    .write = chardriver_write,
    .owner = THIS_MODULE,
};

#define BUFFER_SIZE	1000
static char char_buffer[BUFFER_SIZE];
static int buffer_length = 0;

static dev_t mydev;
static struct cdev *my_cdev;
int my_init_module(void)
{
    int retval;


    /* Load character driver */
    my_cdev = cdev_alloc();
    mydev = MKDEV(major,0);
    retval = register_chrdev_region(mydev,NUMMINORS,name);

    /* Fail to load if register_chardriver fails */
    if (retval < 0)
        return retval;

    /* If major = 0, it if auto-allocated */
    if (!major)
        major = retval;

    if (debug)
        printk("chardriver registered with major = %d\n",major);
    my_cdev->ops = &chardriver_fops;
    my_cdev->owner = THIS_MODULE;
    retval = cdev_add(my_cdev,mydev,NUMMINORS);

    return retval;
}

/*
 * my_cleanup_module()
 *
 * Called when module is removed by insmod.
 */
void my_cleanup_module(void)
{

    /* Unregister character driver. */
    unregister_chrdev_region(mydev,NUMMINORS);
    cdev_del(my_cdev);
}

ssize_t chardriver_read (struct file *filp, char *buf, size_t nbytes, loff_t* ppos)
{
    int avail;
    int failed, transferred;

    if (debug)
        printk("READ: %d bytes\n",(int)nbytes);

    if (*ppos >= buffer_length || !nbytes)
        return 0;

    avail = buffer_length - *ppos;
    if (nbytes > avail)
        nbytes = avail;

    failed = copy_to_user(buf, char_buffer + *ppos, nbytes);
    transferred = nbytes - failed;

    if (!transferred)
        return -EFAULT;
    *ppos += transferred;
    return transferred;

}

ssize_t chardriver_write (struct file *filp, const char *buf, size_t nbytes, loff_t* ppos)
{
    int failed, transferred;
    if (debug)
        printk("WRITE: %d bytes\n",(int)nbytes);

    if (!nbytes)
        return 0;

    if (nbytes >=BUFFER_SIZE)
        nbytes = BUFFER_SIZE-1;

    failed = copy_from_user(char_buffer, buf, nbytes);
    transferred = nbytes - failed;

    if (!transferred)
        return -EFAULT;

    char_buffer[transferred] = '\0';

    printk("%s\n",char_buffer);

    buffer_length = transferred;
    return transferred;
}
module_init(my_init_module);
module_exit(my_cleanup_module);
