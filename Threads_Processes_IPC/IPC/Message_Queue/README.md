- [What is Message Queue](#what)
- [Types of Message Queue](#types)
- [FIFO vs MQ](#comp)
- [MQ Code](#code)

<a name=what></a>
## Message Queue
- This is Linked list of messages stored in Kernel.
- *No Data is Lost* if process-1=writing, process-2=reading. process-2 crashes. Still data would be on queue, reader can come again and read.
```c
Linked list
  | type=4, message="abc" | type=9, message="xyz" |...
```

<a name=what></a>
## Types OF MQ    
- **1. Private:** Between parent & child
- **2. Public:** Anyone knowing Queue Id.        

<a name=comp></a>
## FIFO vs MQ
- **FIFO:** This are simply pipe write(),read(). No notion of message
- **MQ:** This transfers messages(type, text or struct). Receiver will wait for type of message. Several processes can send/recv messages on same queue.

<a name=code></a>
## MQ Code
- _a._ ftok(char `*`pathname, int proj_id): convert a pathname and a project identifier to a unique key
- _b._ msgget(): For sender(return newly created id). For reciever(returns existant id)
- _c._ msgsnd(): Place data on message queue
- _d._ msgrcv(): Retrieve message from queue
- _e._ msgctl(): Destroy message queue

- **Sender**
```c
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct buffer {
    long type;
    char text[100];
};
int main(){
        struct buffer b;
        key_t key;
        int id;

        key = ftok("progfile", 65);

        id = msgget(key, 0666 | IPC_CREAT);
        b.type = 1;

        printf("Write Data : ");
        gets(b.text);

        msgsnd(id, &b, sizeof(b), 0);
        printf("Data send is : %s \n", b.text);

    return 0;
}
$ gcc sender.c -o sender
```
- **Reciever**
```c
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct buffer {
    long type;
    char text[100];
};

int main(){
        struct buffer b;
        key_t key;
        int id;

        key = ftok("progfile", 65);
        id = msgget(key, 0666 | IPC_CREAT);
        msgrcv(id, &b, sizeof(b), 1, 0);

        printf("Data Received is : %s \n",b.text);
        msgctl(id, IPC_RMID, NULL);

    return 0;
}
$ gcc reciever.c -o reciever

# ./sender
Write Data : amit
Data send is : amit

# ./recv
Data Received is : amit
```
