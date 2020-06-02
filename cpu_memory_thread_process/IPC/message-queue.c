/*      message_queue.c

MQ? This is Linked list of messages stored in Kernel.
        |                 |
        |type=1|text="abc"|...  
        |                 |

Process of adding message:
a. ftok(char *pathname, int proj_id): convert a pathname and a project identifier to a unique key
b. msgget(): For sender(return newly created id). For reciever(returns existant id)
c. msgsnd(): Place data on message queue
d. msgrcv(): Retrieve message from queue
e. msgctl(): Destroy message queue.
*/
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

/*
Output:
# ./sender
Write Data : amit
Data send is : amit
# ./recv
Data Received is : amit
*/
