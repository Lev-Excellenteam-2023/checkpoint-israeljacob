#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yisrael");
MODULE_DESCRIPTION("A simple example Linux module.");
MODULE_VERSION("0.01");

//A static function for doing when init module
static int __init lkm_example_init(void) {
        //Print to the log file
	printk(KERN_INFO "Hello, World!\n");
	return 0;
}

//A static function for doing when remove module
static void __exit lkm_example_exit(void) {
        //Print to the log file
	printk(KERN_INFO "Goodbye, World!\n");
}

//Load the func to execute when init.
module_init(lkm_example_init);

//Load the func to execute when remove.
module_exit(lkm_example_exit);
