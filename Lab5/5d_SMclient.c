/* Client shared memory */

#include<stdio.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#define shmsize 27

main()
{
    char *s,*shm;
    int shmid;
    key_t key = 2011;
    
    if( (shmid = shmget(key , shmsize , 0666)) < 0) {
        printf("Server not started !\n");
        exit(1);
    }
    printf("Accessing shared memory ID : %d\n",shmid);
    if( (shm = shmat(shmid , NULL,0)) == (char*)-1){
        perror("Error on shmat\n");
        exit(1);
    }
    printf("Shared memory contents : \n");
    for(s = shm; *s != '\0'; ++s) {
        putchar(*s);
    }
    putchar('\n');
    *shm = '*';
}