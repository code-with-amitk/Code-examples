/*	testebbchar.c
This is user application which used to interact with driver
using device file.

STEPS:
A. open the device file using fd = open()
B. Take string from user to send to driver
C. write on device file as regular file
	write(fd, string..)
D. read from device file
	read(fd, ..)
*/
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
 
#define BUFFER_LENGTH 256
static char receive[BUFFER_LENGTH];
 
int main()
{
	int ret, fd;
   	char stringToSend[BUFFER_LENGTH];

   	printf("Starting User Application...\n");
	fd = open("/dev/ebbchar", O_RDWR);
   	if (fd < 0)
	{
     		perror("Failed to open the device...");
      		return errno;
   	}

   	printf("Enter string to send to driver:\n");
	scanf("%[^\n]%*c", stringToSend);

	printf("Sending to driver [%s].\n", stringToSend);
   	ret = write(fd, stringToSend, strlen(stringToSend));
   	if (ret < 0)
	{
      		perror("Failed to write the message to the device.");
      		return errno;
   	}
 
   	printf("Press ENTER to read back from the driver...\n");
   	getchar();
 
   	printf("Reading from the driver...\n");
   	ret = read(fd, receive, BUFFER_LENGTH);
   	if (ret < 0)
	{
      		perror("Failed to read the message from the device.");
      		return errno;
   	}
   	printf("The received message is: [%s]\n", receive);

   	printf("Good Bye\n");
   	return 0;
}
