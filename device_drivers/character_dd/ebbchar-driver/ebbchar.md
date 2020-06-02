## Steps for Writing Character Device Driver

- Rename this file as **ebbchar.c**

- Take Soure part only and compile.

[Source](http://derekmolloy.ie/writing-a-linux-kernel-module-part-2-a-character-device)

a. Write device driver named 'ebbchar.c'
b. Build the driver ebbchar.ko
```
# make; ls 
	ebbchar.ko
```
c. Insert the driver into kernel
```
# insmod ebbchar.ko	
```
d. Verify driver is inserted
```
# dmesg
```
e. Check listing of driver
```
# lsmod |grep ebb
# ls -ltr /dev/ebb*
	crw-------- 1 root root 238,0 	//238 major no is automatically assigned by kernel
```
f. Write & compile user application to communicate with driver.
```
# vim testebbdriver.c
```
g. Test interaction
```
# ./test
```
h. Remove the driver.
```
# rmmod ebbchar
```


### STEP-1: Declare Headers
```
/*
 linux/init.h:		Provides mark up functions e.g. __init __exit
 linux/module.h:	Loads LKMs into the kernel
 linux/device.h: 	Header to support the kernel Driver Model
 linux/kernel.h:        Contains types, macros, functions for the kernel
 linux/fs.h:            Header for the Linux file system support
 linux/uaccess.h        Required for the copy to user function

 DEVICE_NAME "ebbchar"    The device will appear at /dev/ebbchar
 CLASS_NAME  "ebb"        The device class -- this is a character device driver
*/
#include <linux/init.h>
#include <linux/module.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/fs.h>
#include <linux/uaccess.h>
#define  DEVICE_NAME "ebbchar"
#define  CLASS_NAME  "ebb"
```

### STEP-2: License, Author, Description, Version
```
/*
MODULE_DESCRIPTION: This will be seen in modinfo
MODULE_VERSION: For user information purpose
*/
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Amit Kumar");
MODULE_DESCRIPTION("A simple Linux char driver for the BBB");
MODULE_VERSION("0.1");
```

### STEP-3: Global variables
```
/*
	majorNumber:		Stores the device number -- determined automatically
	message[256]:		String that is passed from userspace
	size_of_message:        size of the string stored
	numberOpens:            Counts the number of times the device is opened
	struct class* charClass: Driver class struct pointer
	struct device* ebbcharDevice: Driver device struct pointer
*/
static int    majorNumber;
static char   message[256] = {0};
static short  size_of_message;
static int    numberOpens = 0;
static struct class*  ebbcharClass  = NULL;
static struct device* ebbcharDevice = NULL;
```

### STEP-4: Declarations for Driver
 ```
static int     dev_open(struct inode *, struct file *);
static int     dev_release(struct inode *, struct file *);
static ssize_t dev_read(struct file *, char *, size_t, loff_t *);
static ssize_t dev_write(struct file *, const char *, size_t, loff_t *);
```

### STEP-5: File Operations Structure (/linux/fs.h)
```
/*
- Provides callback functions that needed to be called from user space
struct file_operations{
    struct module *owner;
    loff_t (*llseek) (struct file *, loff_t, int);
    ssize_t (*read) (struct file *, char *, size_t, loff_t *);
    ssize_t (*write) (struct file *, const char *, size_t, loff_t *);
    ssize_t (*readdir) (struct file *, void *, filldir_t);
    unsigned int (*poll) (struct file *, struct poll_table_struct *);
    int (*ioctl) (struct inode *, struct file *, unsigned int, unsigned long);
    int (*mmap) (struct file *, struct vm_area_struct *);
    int (*open) (struct inode*, struct file*);
    int (*flush) (struct file*);
    int (*release) (struct inode*, struct file*);
    int (*fsync) (struct file*, struct dentry *, int datasync,);
    int (*fasync) (int, struct file*, int);
    int (*lock) (struct file*, struct file_lock *);
    int (*readv) (struct file*, const struct iovec *, unsigned long, loff_t *);
    int (*writev) (struct file*, const struct iovec *, unsigned long, loff_t *);
    int (*sendpage) (struct file*, struct page*, int, size_t, loff_t *, int);
    unsigned long (*get_unmapped_area) (struct file*, unsinged long, unsinged long, unsinged long, unsinged long);
};
It is not necessary to implement all functions. If function is not implemented corresponding pointer = 0.
*/ 

static struct file_operations fops =
{
   .open = dev_open,
   .read = dev_read,
   .write = dev_write,
   .release = dev_release,
};
```

#### STEP-6: LKM initialization function.
```
/*
	This function is called using module_init()
- register_chrdev() register your character DD

int register_chrdev_region(dev_t first, unsigned int count, char name);  	
-  Obtain 1 or more device numbers                                                                                
 Parameters:                                                                   
        first: beginning device number of the range you would like to allocate 
        count: total number of contiguous device numbers you are requesting    
        name: name of the device that should be associated with this range     
                it will appear in /proc/devices and sysfs                      
 Returns:                                                                      
        0: if the allocation was successfully performed                        
        -ve: In error, error code will be returned                             
 Notes:                                                                
        declared in <linux/fs.h>                                               

int alloc_chrdev_region(dev_t dev, unsigned int firstminor,                   
                          unsigned int count, char name); 	
-Obtain 1 or more device numbers dynamically(on run time).                  
  Kernel will allocate the device numbers.                                    
 Parameters:                                                                 
        dev: Output parameter, pointer to allocated device numbers.           
        firstminor: requested first minor number to use; it is usually 0      
        count: same as register_chrdev_region                                 
        name: same as register_chrdev_region                                  
 Returns:                                                                    
      0: if the allocation was successfully performed                        
      -ve: In error, error code will be returned                             
 Notes:                                                                      
      declared in <linux/fs.h>                                               
*/

static int __init ebbchar_init(void){
	printk(KERN_INFO "Initializing the EBBChar LKM\n");

   	//We should use alloc_chrdev_region instead
	//register_chrdev() is older approach, now-a-days kernel uses cdev_init(&fops)
	majorNumber = register_chrdev(0, DEVICE_NAME, &fops);
   	if (majorNumber<0)
   	{
      		printk(KERN_ALERT "EBBChar failed to register a major number\n");
      		return majorNumber;
   	}

   	printk(KERN_INFO "EBBChar: registered with major number %d\n", majorNumber);

   	//Registering device class
   	ebbcharClass = class_create(THIS_MODULE, CLASS_NAME);
   	if (IS_ERR(ebbcharClass))
	{
      		unregister_chrdev(majorNumber, DEVICE_NAME);
	      	printk(KERN_ALERT "Failed to register device class\n");
	      	return PTR_ERR(ebbcharClass);
   	}

   	printk(KERN_INFO "EBBChar: device class registered correctly\n");

   	//Register the device driver
   	ebbcharDevice = device_create(ebbcharClass, NULL, MKDEV(majorNumber, 0), NULL, DEVICE_NAME);
   	if (IS_ERR(ebbcharDevice))
      		class_destroy(ebbcharClass);
      		unregister_chrdev(majorNumber, DEVICE_NAME);
      		printk(KERN_ALERT "Failed to create the device\n");
      		return PTR_ERR(ebbcharDevice);
   	}

   	printk(KERN_INFO "EBBChar: device class created correctly\n");

   	return 0;
}
```

#### Step-7: LKM exit function to be called from module_exit()  - Does cleanup tasks
```
static void __exit ebbchar_exit(void)
{
	device_destroy(ebbcharClass, MKDEV(majorNumber, 0));    
   	class_unregister(ebbcharClass);                          
   	class_destroy(ebbcharClass);                            
   	unregister_chrdev(majorNumber, DEVICE_NAME);            
   	printk(KERN_INFO "EBBChar: Goodbye from the LKM!\n");
}
```

#### STEP-8: Provide Function to be called from user space applications.
```
/*
 dev_open(): called each time device file is opened
 dev_read(): called when device file is read from user space
 	copy_to_user(): function to send the buffer string to the user 
	and captures any errors
 dev_write(): called when device file is written from user space i.e. data
 		is sent to the device from the user.
 dev_release(): Called when user space calls close() on device file
*/
static int dev_open(struct inode *inodep, struct file *filep)
{
	numberOpens++;
   	printk(KERN_INFO "EBBChar: Device has been opened %d time(s)\n", numberOpens);
   	return 0;
}

static ssize_t dev_read(struct file *filep, char *buffer, size_t len, loff_t *offset)
{
	int error_count = 0;

   	//copy_to_user has the format ( * to, *from, size) and returns 0 on success
   	error_count = copy_to_user(buffer, message, size_of_message);

   	if (error_count==0)
   	{
      		printk(KERN_INFO "EBBChar: Sent %d characters to the user\n", size_of_message);
      		return (size_of_message=0);  //clear the position to the start and return 0
   	}else 
	{
      		printk(KERN_INFO "EBBChar: Failed to send %d characters to the user\n", error_count);
      		return -EFAULT;              //-14
   	}
}

static ssize_t dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset)
{
	sprintf(message, "%s(%zu letters)", buffer, len);   //appending received string with its length
   	size_of_message = strlen(message);                 //store the length of the stored message
   	printk(KERN_INFO "EBBChar: Received %zu characters from the user\n", len);
   	return len;
}

static int dev_release(struct inode *inodep, struct file *filep)
{
	printk(KERN_INFO "EBBChar: Device successfully closed\n");
   	return 0;
}
```

#### STEP-9:  Initialization, cleanup functions for module. Use module_init(), module_exit() provided in linux/init.h
``` 
module_init(ebbchar_init);
module_exit(ebbchar_exit);
```
