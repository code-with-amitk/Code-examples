- **[Source Code](http://derekmolloy.ie/writing-a-linux-kernel-module-part-2-a-character-device)**
  - Rename this file as **ebbchar.c**

## Steps 

**Write Drive Source**
- *1.* Declare Headers, License, Author, Description, Version, Declare Global variables, Declare the prototype of functions those whould be invoked using callbacks.
- *2.* **file_operations structure** Provides callback functions that needed to be called from user space. It is not necessary to implement all functions. If function is not implemented corresponding pointer = 0
- *3.* Define the function to be called at time of device driver initialization. This function is passed as parameter to module_init().
  - Create device file from device driver dynamically using `register_chrdev`.
  - Register device class
  - Register the device driver
- *4.* Define function to be called at module_exit() ie doing clean up tasks.
- *5.* Provide Function to be called from user space applications.
  - dev_open(): called each time device file is opened
  - dev_read(): called when device file is read from user space
  - copy_to_user(): function to send the buffer string to the user and captures any errors
  - dev_write(): called when device file is written from user space i.e. data is sent to the device from the user.
  - dev_release(): Called when user space calls close() on device file
- *6.* Provide Initialization, cleanup functions to module_init(), module_exit()
```c
# vim ebbchar.c
 linux/init.h:		Provides mark up functions e.g. __init __exit          //1
 linux/module.h:	Loads LKMs into the kernel
 linux/device.h: 	Header to support the kernel Driver Model
 linux/kernel.h:        Contains types, macros, functions for the kernel
 linux/fs.h:            Header for the Linux file system support
 linux/uaccess.h        Required for the copy to user function

 DEVICE_NAME "ebbchar"    The device will appear at /dev/ebbchar
 CLASS_NAME  "ebb"        The device class -- this is a character device driver

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Amit Kumar");
MODULE_DESCRIPTION("A simple Linux char driver for the BBB");         //This will be seen in modinfo
MODULE_VERSION("0.1");

static int    majorNumber;                                            //Stores the device number -- determined automatically
static char   message[256] = {0};                                     //String that is passed from userspace
static short  size_of_message;                                        //size of the string stored
static int    numberOpens = 0;                                        //Counts the number of times the device is opened
static struct class*  ebbcharClass  = NULL;                           //Driver class struct pointer
static struct device* ebbcharDevice = NULL;                          //Driver device struct pointer

static int     dev_open(struct inode *, struct file *);			
static int     dev_release(struct inode *, struct file *);
static ssize_t dev_read(struct file *, char *, size_t, loff_t *);
static ssize_t dev_write(struct file *, const char *, size_t, loff_t *);

static struct file_operations fops = {                               //2
   .open = dev_open,
   .read = dev_read,
   .write = dev_write,
   .release = dev_release,
};

static int __init ebbchar_init(void){                                              //3
  printk(KERN_INFO "Initializing the EBBChar LKM\n");

  //Use alloc_chrdev_region() instead
  if( (majorNumber = register_chrdev(0, DEVICE_NAME, &fops)) < 0){                  //3a
    printk(KERN_ALERT "EBBChar failed to register a major number\n");
    return majorNumber;
  }

  printk(KERN_INFO "EBBChar: registered with major number %d\n", majorNumber);

  ebbcharClass = class_create(THIS_MODULE, CLASS_NAME);                              //3b
  if (IS_ERR(ebbcharClass)) {
    unregister_chrdev(majorNumber, DEVICE_NAME);
    printk(KERN_ALERT "Failed to register device class\n");
    return PTR_ERR(ebbcharClass);
  }

  ebbcharDevice = device_create(ebbcharClass, NULL, MKDEV(majorNumber, 0), NULL, DEVICE_NAME);   //3c
  if (IS_ERR(ebbcharDevice)) {
    class_destroy(ebbcharClass);
    unregister_chrdev(majorNumber, DEVICE_NAME);
    printk(KERN_ALERT "Failed to create the device\n");
    return PTR_ERR(ebbcharDevice);
  }
  printk(KERN_INFO "EBBChar: device class created correctly\n");
  return 0;
}

static void __exit ebbchar_exit(void){                                       //4
  device_destroy(ebbcharClass, MKDEV(majorNumber, 0));    
  class_unregister(ebbcharClass);                          
  class_destroy(ebbcharClass);                            
  unregister_chrdev(majorNumber, DEVICE_NAME);            
  printk(KERN_INFO "EBBChar: Goodbye from the LKM!\n");
}

static int dev_open(struct inode *inodep, struct file *filep){                 //5a
  numberOpens++;
  printk(KERN_INFO "EBBChar: Device has been opened %d time(s)\n", numberOpens);
  return 0;
}

static ssize_t dev_read(struct file *filep, char *buffer, size_t len, loff_t *offset){     //5b
  int error_count = 0;
  //copy_to_user has the format ( * to, *from, size) and returns 0 on success
  error_count = copy_to_user(buffer, message, size_of_message);

  if (error_count==0){
    printk(KERN_INFO "EBBChar: Sent %d characters to the user\n", size_of_message);
    return (size_of_message=0);  //clear the position to the start and return 0
  } else {
    printk(KERN_INFO "EBBChar: Failed to send %d characters to the user\n", error_count);
    return -EFAULT;              //-14
  }
}

static ssize_t dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset){      //5c
  sprintf(message, "%s(%zu letters)", buffer, len);   //appending received string with its length
  size_of_message = strlen(message);                 //store the length of the stored message
  printk(KERN_INFO "EBBChar: Received %zu characters from the user\n", len);
  return len;
}

static int dev_release(struct inode *inodep, struct file *filep){
	printk(KERN_INFO "EBBChar: Device successfully closed\n");
   	return 0;
}

module_init(ebbchar_init);                                    //6
module_exit(ebbchar_exit);
```

- *7.* Build driver ebbchar.ko
```c
# make; 
# ls 
  ebbchar.ko
```

- *8.* Insert/Register Device Driver, Verify driver & Device file being created
```c
# insmod ebbchar.ko	
# dmesg
# lsmod |grep ebb                     //Check listing of driver
# ls -ltr /dev/ebb*                   //Device file
  crw-------- 1 root root 238,0      //238 major no is automatically assigned by kernel
```
- *9.* Write/compile/Test user application to communicate with driver.
  - Note, User space application should be aware of Device file `/dev/ebbchar`.
  - User space application will open this device and do RW operation on it
```c
# vim testebbdriver.c
..
fd = open("/dev/ebbchar", O_RDWR);
write(fd, stringToSend, strlen(stringToSend));
read(fd, receive, BUFFER_LENGTH); 
..c
# ./test
```

- *10.* Remove the driver.
```c
# rmmod ebbchar
```



## Data Structures
- struct file_operations
```c
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
```

## Functions

| API | Purpose | Parameters | Return |
| --- | --- | --- | --- |
| int register_chrdev_region() | Register character DD | <ul><li>first: beginning device number of the range you would like to allocate</li></ul> <ul><li>count: total number of contiguous device numbers you are requesting</li></ul> <ul><li>name: name of the device that should be associated with this range it will appear in /proc/devices and sysfs</li></ul> | Major Number |
| modprobe | to add and remove modules from the Linux Kernel | module name | |
