#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
 
#define BUFFER_LENGTH 256 
static char receive[BUFFER_LENGTH];
int main(){
	int ret, fd;
	char stringToSend[BUFFER_LENGTH];

   	printf("\nStarting device driver Handler code..\n");

   	if((fd = open("/dev/amit_device_file", O_RDWR)) < 0){
      		perror("Failed to open the /dev/amit_device_file \n");
      		return errno;
   	}
	printf("\n Opened Device file /dev/amit_device_file\n");

   	printf("Type String to send to kernel module:\n");
	scanf("%[^\n]%*c", stringToSend);
   	
	printf("Writing message to /dev/amit_device_file [%s].\n", stringToSend);
   	if(write(fd, stringToSend, strlen(stringToSend)) < 0){
      		perror("Failed to write the message to the device /dev/amit_device_file");
      		return errno;
   	}
	printf("\nWritten message to /dev/amit_device_file\n");
	//sleep(20);
 
   	printf("Press ENTER to read back from the device...\n");
   	getchar();
 
   	printf("Reading from the device...\n");
   	if(read(fd, receive, BUFFER_LENGTH) < 0){
      		perror("Failed to read the message from the device.");
      		return errno;
   	}

   	printf("The received message is: [%s]\n", receive);
   	printf("End of the program\n");
   	return 0;
}
