/*	simple_hello_world.c

- Note only super user can load and unload module.
- Your module’s code has to be recompiled for each version of the kernel.

[PREREQUISITE] Install kernel source.	# yum install kernel-devel -y

Step-A: MODULE_LICENSE: Tell kernel module us under free license

Step-B: Define functions to be called at module load & exit. 

Step-C: Call these function in module_init() & module_exit()

Step-D: Create Makefile;	# make

Step-E: Load the module		# insmod ./hello.ko
	# dmesg
	hello: loading out-of-tree module
	Keep Building Everyday

STEP-F: List modules loaded in kernel	# lsmod
	- lsmod reads /proc/modules virtual file.
	- Information on currently loaded modules can also be found in sysfs virtual filesystem:
		/sys/module
	# lsmod |grep hello
	hello	16384	0

Step-G: Unload the module	# rmmod hello-world
	Note that module removal fails if the kernel believes that the module is still in use
	# dmesg
	Matarani will do for me
*/


#include <linux/init.h>
#include <linux/module.h>

// A. MODULE_LICENSE: macro telling kernel that this module has free license, else kernel complains when the module is loaded
MODULE_LICENSE("Dual BSD/GPL");

//B. define functions to be called at time of module load & exit
static int hello_init(void)
{
	printk(KERN_ALERT "Keep Building Everyday\n");
	return 0;
}
static void hello_exit(void)
{
	printk(KERN_ALERT "Matarani will do for me\n");
}

//C. hello_init() is called when kernel is loaded. module_init is macro
module_init(hello_init);

//hello_exit() is called when kernel is removed. module_exit is macro
module_exit(hello_exit);
