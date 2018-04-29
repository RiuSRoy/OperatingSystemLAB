/* Shared memory server */

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#define shmsize 27

main()
{
    char *s,*shm;
    int shmid;
    char c;
    key_t key = 2011;    
    if( (shmid = shmget(key , shmsize , IPC_CREAT|0666)) < 0) {
        perror("Error on shmget\n");
        exit(1);
    }
    printf("Shared Memory ID : %d\n",shmid);
    if( (shm = shmat(shmid , NULL,0)) == (char*)-1) {
        perror("Error on shmat\n");
        exit(1);
    }
    memset(shm , 0 , shmsize);
    s = shm;
    for(c = 'a';c <= 'z' ;++c) {
        *s++ = c;
    }
    *s = '\0';
    while(*shm != '*');
    printf("Client finished reading!\n");
    if(shmdt(shm) != 0) {
        fprintf(stderr , "Could not close memory segment\n");
    }
    shmctl(shmid , IPC_RMID , 0);
}


/*Two or more processes share a single chunk of memory to
communicate randomly.
Semaphores are generally used to avoid race condition amongst processes.
Fastest amongst all IPCs as it does not require any system call.
It avoids copying data unnecessarily.*/