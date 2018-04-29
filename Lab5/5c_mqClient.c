/* Client chat process */

#include<stdio.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct mesgq{
    long type;
    char text[200];
} mq;

main() 
{
    int msqid , len;
    key_t key= 200;
    if( (msqid = msgget(key, 0644)) == -1) {
        printf("Server not active !\n");
        exit(1);
    }
    printf("Client ready :\n");
    while( msgrcv(msqid , &mq , sizeof(mq.text) , 0 , 0) != -1) {
        printf("From Server : '%s'\n",mq.text);

        fgets(mq.text , sizeof(mq.text) , stdin);
        len = strlen(mq.text);
        if(mq.text[len - 1] == '\n'){
            mq.text[len - 1] = '\0';
        }
        msgsnd(msqid , &mq , len+1 , 0);
    }
    printf("Server Disconnected\n");
}

/*   Message Queue :
A message queue is a linked list of messages stored within
the kernel A message queue is identified by a unique identifier
Every message has a positive long integer type field, a non-negative
length, and the actual data bytes.The messages need not be fetched on
 FCFS basis. It could be based on type field. */