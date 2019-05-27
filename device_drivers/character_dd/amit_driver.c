/*
 @file   amit_driver.c
 @brief   Character driver. This module maps to /dev/ebbchar and comes with a helper C program that can be run in Linux user space to communicate with this the LKM.

  kernel-space						User-Space
  amit_driver	<->	/dev/amit_device_file	<->	helper_prog
*/
 
#include <linux/init.h>           //Macro Definitions for  __init __exit provided here
#include <linux/module.h>         //Header for loading LKMs into the kernel
#include <linux/device.h>         //Header to support the kernel Driver Model
#include <linux/kernel.h>         //Contains types, macros, functions for the kernel
#include <linux/fs.h>             //Header for the Linux file system support
#include <linux/uaccess.h>          //Required for the copy to user function
#define  DEVICE_NAME "amit_device_file"    //The device will appear at /dev/amit_device_file
#define  CLASS_NAME  "amit"        //< The device class -- this is a character device driver
 
MODULE_LICENSE("GPL");            //The license type -- this affects available functionality
MODULE_AUTHOR("Amit");    //The author -- visible when you use modinfo
MODULE_DESCRIPTION("Amit's simple Linux char driver for TESTING");  //The description -- see modinfo
MODULE_VERSION("0.1");            //Version number to inform users
 
static int    majorNumber;                  //Stores the device number -- determined automatically
static char   message[256] = {0};           //Memory for the string that is passed from userspace
static short  size_of_message;              //Used to remember the size of the string stored
static int    numberOpens = 0;              //Counts the number of times the device is opened
//static struct class *ebbcharClass  = NULL; //The device-driver class struct pointer
static struct class *classPtr  = NULL; //The device-driver class struct pointer
//static struct device * ebbcharDevice = NULL; //The device-driver device struct pointer
static struct device *devicePtr = NULL; //The device-driver device struct pointer

static int     dev_open(struct inode *, struct file *);
static int     dev_release(struct inode *, struct file *);
static ssize_t dev_read(struct file *, char *, size_t, loff_t *);
static ssize_t dev_write(struct file *, const char *, size_t, loff_t *);
 
/* -Devices are represented as file structure in the kernel.
  - The file_operations structure from /linux/fs.h lists the callback functions that you wish to associated with your file operations
  - char devices usually implement open, read, write and release calls

  Device Driver
  struct file_opeartions ops{ .open = dev_open }
  register_chrdev (&ops)
						User-space-Helper
						open("/dev/amit_device_file",O_RDWR)
  dev_open(){
   //Call reaches here
  }
*/
static struct file_operations fops =
{
   .open = dev_open,
   .read = dev_read,
   .write = dev_write,
   .release = dev_release,
};
 
/*The LKM initialization function
 __init: means that for a built-in driver(not a LKM) this function is only used at initialization time and that it can be discarded and its memory freed up after that point.
 - return returns 0 if successful
*/
static int __init amit_driver_init(void){
	printk(KERN_INFO "AmitDriver: Initializing the Amit Device Driver LKM..\n");	//printk will logged in /var/log/messages

/*register_chrdev(unsigned int  major, 
		  const char *name, 			//Device file name
		  const struct file_operations *fops)	//file operations associated with this device
 What? Register a major number for character devices
*/
	majorNumber = register_chrdev(0, DEVICE_NAME, &fops);
	if (majorNumber<0){
      		printk(KERN_ALERT "AmitDriver failed to register a major number\n");
		return majorNumber;
   	}

	printk(KERN_INFO "AmitDriver: register_chrdev() Succeed majorNo:%d\n", majorNumber);

//struct class *class_create(struct module *owner,const char *name): Creates struct class pointer, then be used in calls to class_device_create
	classPtr = class_create(THIS_MODULE, CLASS_NAME);
	if (IS_ERR(classPtr)){                // Check for error and clean up if there is
      		unregister_chrdev(majorNumber, DEVICE_NAME);
      		printk(KERN_ALERT "Failed to register device class\n");
      		return PTR_ERR(classPtr);          // Correct way to return an error on a pointer
   	}

//device_create(): creates a device and registers it with sysfs
//MKDEV(majorNo, minorNo): 
    	devicePtr = device_create(classPtr, NULL, MKDEV(majorNumber, 0), NULL, DEVICE_NAME);
	if (IS_ERR(devicePtr)){               // Clean up if there is an error
      		class_destroy(classPtr);           // Repeated code but the alternative is goto statements
      		unregister_chrdev(majorNumber, DEVICE_NAME);
      		printk(KERN_ALERT "AmitDriver: Failed to create the device\n");
      		return PTR_ERR(devicePtr);
   	}

   	printk(KERN_INFO "AmitDriver: device file created correctly\n"); // Made it! device was initialized
   	return 0;
}
 
static void __exit amit_driver_exit(void){
   device_destroy(classPtr, MKDEV(majorNumber, 0));     // remove the device
   class_unregister(classPtr);                          // unregister the device class
   class_destroy(classPtr);                             // remove the device class
   unregister_chrdev(majorNumber, DEVICE_NAME);             // unregister the major number
   printk(KERN_INFO "AmitDeviceDriver: Unloaded/Removed!\n");
}

/* The device open function that is called each time the device is opened
  @param inodep A pointer to an inode object (defined in linux/fs.h)
  @param filep A pointer to a file object (defined in linux/fs.h)
*/
static int dev_open(struct inode *inodep, struct file *filep){
	numberOpens++;
	printk(KERN_INFO "/dev/amit_device_file opened by User Space Program attempt(%d)\n", numberOpens);
	return 0;
}
 
/* User space program called read() on device file.
   @param filep A pointer to a file object (defined in linux/fs.h)
   @param buffer The pointer to the buffer to which this function writes the data
   @param len The length of the b
   @param offset The offset if required
*/
static ssize_t dev_read(struct file *filep, char *buffer, size_t len, loff_t *offset){
	int error_count = 0;
	error_count = copy_to_user(buffer, message, size_of_message);
 
   	if (error_count==0){
     		printk(KERN_INFO "amit_device_driver: Sent %d characters to the user\n", size_of_message);
      		return (size_of_message=0);
   	}else{
      		printk(KERN_INFO "amit_device_driver: Failed to send %d characters to the user\n", error_count);
      		return -EFAULT;
   	}
}
 
/* User space program called read() on device file.
   @param filep A pointer to a file object
   @param buffer The buffer to that contains the string to write to the device
   @param len The length of the array of data that is being passed in the const char buffer
   @param offset The offset if required
*/
static ssize_t dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset){
   	printk(KERN_INFO "amit_device_driver: Inside dev_write() recieved [%s] from the user\n", buffer);
	strcpy(message,buffer);
	size_of_message = strlen(message);
   	return len;
}
 
/* Device file is closed/released by userspace program.
   @param inodep A pointer to an inode object (defined in linux/fs.h)
   @param filep A pointer to a file object (defined in linux/fs.h)
*/
static int dev_release(struct inode *inodep, struct file *filep){
   printk(KERN_INFO "/dev/amit_device_file closed successfully\n");
   return 0;
}
 
module_init(amit_driver_init);	//module_init(): which function is to be called at module insertion time/Boot time
module_exit(amit_driver_exit);	//module_exit(): cleanup function at exit time

/*
!!!!!How to Run the program!!!!!!!!
 # insmod amit_driver.ko
 # tail -f /var/log/messages
 # rmmod amit_driver.ko


!!!!!!!!!!!!!!!!!!!!!!Summary of Steps!!!!!!!!!!!!!!!!!!!
==========DEVICE DRIVER==============
1. Fill file_operations structure
static struct file_operations fops =
{
   .open = dev_open,
   .read = dev_read,
   .write = dev_write,
   .release = dev_release,
};

2. module_init(driver_init)	//calls driver_init()
driver_init(){
	majorNumber = register_chrdev(0, device_file_name, &fops);	//Register a major number for character devices

	classPtr = class_create(THIS_MODULE, CLASS_NAME);	//Create class pointer

	devicePtr = device_create(classPtr, NULL, MKDEV(majorNumber, 0), NULL, DEVICE_NAME);	//creates a device and registers it with sysfs
}

3. Device Driver waits for action on device file

4. dev_write(struct file *filep, const char *buffer, size_t len, loff_t *offset){
	printfk("Read %s from user space", buffer);
   }

5. dev_read(){
	copy_to_user(buffer, message, size_of_message);
   }
=========================================

-----------User_space_handler-------------
1. int main(){
	fd = open("/dev/amit_device_file", O_RDWR)	//Open device file	=calls=>	dev_open() in Driver
	scanf("%s",<enter-message-to-send-to-Driver>);

	write(fd, stringToSend, strlen(stringToSend)	//Write to device file	=calls=>	dev_write() in Driver

	read(fd, buf, 256);	//Read from device file		=calls=>	dev_read() in driver

	close(fd)	=calls=>	dev_release in driver
 }


!!!!!!!!!!!!!!!!!!!!!!!!!!Error Messages!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
Issue-1
  # make
    /lib/modules/3.10.0-933.el7.x86_64/build: No such file or Directory
Solution:
 # yum install kernel-devel
 # cd /lib/modules/3.10.0-933.el7.x86_64
 # rm -rf build
 # ln -s /lib/modules/3.10.0-933.el7.x86_64/build /usr/src/kernel/3.10.0-933.el7.x86_64/ 
*/
