### Steps
- *1.* Write driver source code.
```c
#include <linux/init.h>
#include <linux/module.h>

MODULE_LICENSE("Dual BSD/GPL");	        // A. macro telling kernel that this module has free license

static int hello_init(void) {            //B. define functions to be called at time of module load & exit
  printk(KERN_ALERT "Keep Building Everyday\n");
  return 0;
}
static void hello_exit(void) {
	printk(KERN_ALERT "Matarani will do for me\n");
}

//Define functions to be called at module load & exit. module_init() & module_exit()
module_init(hello_init);                 //C. hello_init() is called when kernel is loaded. module_init is macro
module_exit(hello_exit);                 //hello_exit() is called when kernel is removed. module_exit is macro
```
- *2.* Create [Makefile](../)
```c
# make
```
- *3.* Load & check module is loaded?
```c
  # insmod ./hello.ko
  # dmesg
    hello: loading out-of-tree module
    Keep Building Everyday
  # lsmod |grep hello               //List modules loaded in kernel. lsmod reads /proc/modules virtual file.
      hello	16384	0
```			
- *4.* Unload the module	
```c
  # rmmod hello-world	          //Note that module removal fails if the kernel believes that the module is still in use
```
