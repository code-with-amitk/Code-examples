Take source code and place in hello.c

Note only super user can load and unload module.
	
Your module’s code has to be recompiled for each version of the kernel.

#### PREREQUISITE
Install kernel source.	# yum install kernel-devel -y

### Steps

1. MODULE_LICENSE: Tell kernel module us under free license
2. Define functions to be called at module load & exit. 
3. Call these function in module_init() & module_exit()
4. Create Makefile;	# make
5. Load the module		# insmod ./hello.ko
```C
	# dmesg
	hello: loading out-of-tree module
	Keep Building Everyday
```	

6. List modules loaded in kernel	# lsmod
	- lsmod reads /proc/modules virtual file.
	- Information on currently loaded modules can also be found in sysfs virtual filesystem:
		/sys/module
```		
	# lsmod |grep hello
	hello	16384	0
```			

7. Unload the module	# rmmod hello-world
	Note that module removal fails if the kernel believes that the module is still in use
```	
	# dmesg
	Matarani will do for me
```	

### Complete Source code
```C
#include <linux/init.h>
#include <linux/module.h>

// A. MODULE_LICENSE: macro telling kernel that this module has free license, 
//else kernel complains when the module is loaded
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
```
