/*      named-pipe-fifo.c

NAMED-PIPE(mkfifo)?
When processes exchange data via the FIFO, kernel passes all data internally without writing it to the file. Thus file name merely serves as a reference point so that processes can access the pipe using the name.

FIFO vs normal-file: No data is kept on FIFO, all is exchanged via kernel buffers.
*/
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#ifdef WRITER
int main(){
    int fd1;
    char str1[80], str2[80];

    char * myfifo = "/tmp/amit_myfifo";

    mkfifo(myfifo, 0666);

    while (1){
        fd1 = open(myfifo,O_RDONLY);
        read(fd1, str1, 80);

        printf("Read: %s\n", str1);
        close(fd1);
    }
    return 0;
}
//#gcc writer.c -o WRITER
#endif

#ifdef READER
int main(){
    int fd;
    char arr1[80], arr2[80];

    char * myfifo = "/tmp/amit_myfifo";
    mkfifo(myfifo, 0666);

    while (1){
        fd = open(myfifo, O_WRONLY);

        fgets(arr2, 80, stdin);

        write(fd, arr2, strlen(arr2)+1);
        close(fd);
    }
    return 0;
}
//#gcc reader.c -o READER
#endif

/*
Output
[TERMINAL-1]
#./WRITER
amit

[TERMINAL-2]
#./READER
Read: amit

# ls -ltr /tmp/amit_myfifo
prw-r--r--. 1 root root 0 Feb 18 19:23 /tmp/amit_myfifo
- regular file
d directory
b block type special file
c character type special file
l symbolic link
p pipe
s socket
*/
