## Message Queues
- This is Linked list of messages stored in Kernel.
```c        
        Linked list     | type=4, message="abc" | type=9, message="xyz" |...
```        
- **No Data Lost.** if process-1 is writing, process-2 is reading. process-2 crashes. Still data would be on queue, reader can come again and read. 
- **TYPES OF MQ:**    
  - *1.* Private: Between parent & child
  - *2.* Public: Anyone knowing Queue Id.        
- **FIFO vs MQ**

|FIFO|MQ|
|---|---|          
|This are simply pipe write(),read(). No notion of message|This transfers messages(type, text or struct). Receiver will wait for type of message. Several processes can send/recv messages on same queue.|

- **Process of adding message:**
  - a. ftok(char `*`pathname, int proj_id): convert a pathname and a project identifier to a unique key
  - b. msgget(): For sender(return newly created id). For reciever(returns existant id)
  - c. msgsnd(): Place data on message queue
  - d. msgrcv(): Retrieve message from queue
  - e. msgctl(): Destroy message queue.

### Code
```c        
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#ifdef SENDER
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
//#gcc sender.c -o sender
#endif

#ifdef RECIEVER
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
//#gcc reciever.c -o reciever
#endif

# ./sender
Write Data : amit
Data send is : amit

# ./recv
Data Received is : amit
```
