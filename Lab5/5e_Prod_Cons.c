/* Producer Consumer Problem */

#include<stdio.h>
#include<sys/sem.h>
#include<sys/ipc.h>

#define N 5
#define BUFSIZE 1
#define PERMS 0666

int nextP = 0, nextC = 0;
int *buffer;
int mutex , full , empty;

void producer()
{
    if(nextP == N){
        nextP = 0;
    }
    printf("Enter data for producer to produce : ");
    scanf("%d", (buffer + nextP));
    nextP++;    
}

void consumer()
{
    if(nextC == N){
        nextC = 0;
    }
    int g = *(buffer + nextC++);
    printf("\nConsumer consumes data %d",g);
}

void sem_op(int id, int value)
{
    struct sembuf op;
    int v;
    op.sem_num = 0;
    op.sem_flg = SEM_UNDO;
    op.sem_op = value;
    if( (v = semop(id , &op, 1)) < 0) {
        printf("\nError executing semop instruction");
    }
}

void sem_create(int id, int initial_val)
{
    int semval;
    union semun
    {
        int val;
        struct semid_ds *buf;
        unsigned short *array;
    } s;
    s.val = initial_val;
    if( (semval = semctl(id , 0 , SETVAL , s)) < 0 ) {
        printf("\nError in executing semctl");
    }
}

void sem_wait(int id)
{
    sem_op(id , -1);
}

void sem_signal(int id)
{
    sem_op(id , 1);
}
main()
{
    int shmid , i;
    pid_t pid;
    if( (shmid = shmget(1000 , BUFSIZE , IPC_CREAT|PERMS)) < 0 ) {
        printf("\nUnable to create shared memory");
        return;
    }
    if( (buffer = (int*)shmat(shmid , (char*)0 , 0)) == (int*)-1 ) {
        printf("\nShared memory Allocation error\n");
        exit(1);
    }
    if( (mutex = semget(IPC_PRIVATE , 1 , PERMS|IPC_CREAT)) == -1) {
        printf("\nCan't create mutex semaphore!\n");
        exit(1);
    }
    if( (empty = semget(IPC_PRIVATE , 1 , PERMS|IPC_CREAT)) == -1) {
        printf("\nCan't create empty semaphore!\n");
        exit(1);
    }
    if( (full = semget(IPC_PRIVATE , 1 , PERMS|IPC_CREAT)) == -1) {
        printf("\nCan't create full semaphore!\n");
        exit(1);
    }
    sem_create(mutex , 1);
    sem_create(empty , N);
    sem_create(full , 0);

    if((pid = fork()) < 0) {
        printf("\nError in process creation");
        exit(1);
    }
    else if(pid > 0) {
        for(i = 0 ; i < N ; ++i) {
            sem_wait(empty);
            sem_wait(mutex);
            producer();
            sem_signal(mutex);
            sem_signal(full);
        }
    }
    else {
        for(i = 0 ; i < N ; ++i) {
            sem_wait(full);
            sem_wait(mutex);
            consumer();
            sem_signal(mutex);
            sem_signal(empty);
        }
        printf("\n");
    }
}