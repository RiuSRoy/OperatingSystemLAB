/* server chat process */

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
    int msqid, len;
    key_t key = 200;
    if( (msqid = msgget(key , 0644|IPC_CREAT)) == -1) {
        perror("Error on mssget!\n");
        exit(1);
    }
    printf("Enter text , Ctrl+D to quit : \n");
    mq.type = 1;
/* fgets(char *str, int n, FILE *stream) reads a line from the
specified stream and stores it into the string pointed to by str. */
    while(fgets(mq.text , sizeof(mq.text) , stdin) != NULL) {
        len = strlen(mq.text);
        if(mq.text[len - 1] == '\n'){
            mq.text[len - 1] = '\0';
        }
        msgsnd(msqid , &mq , len+1 , 0);
        msgrcv(msqid , &mq , sizeof(mq.text) , 0 , 0);// 4th arg = __mdgtyp
        printf("From Client : '%s'\n",mq.text);
    }
    //msgctl : message control operations
    msgctl(msqid , IPC_RMID , NULL);
}

/* IPC RMID  
Immediately remove the message queue, awakening all waiting
reader and writer processes (with an error return and errno
set to EIDRM). The calling process must have appropriate privileges
or its effective user ID must be either that of the creator or
owner of the message queue.  */

