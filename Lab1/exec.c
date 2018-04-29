#include<stdio.h>
#include<unistd.h> //fork()
#include<sys/types.h> //pid_t , fork()
#include<stdlib.h>

main(int argc , char* argv[])
{
    pid_t pid;
    if(argc != 3) {
        printf("\nInsufficient arguments to load program");
        printf("\nUsage : ./a.out <path> <cmd>\n");
        exit(-1);
    }
    pid = fork();
    if(pid < 0) {
        printf("Process creation unsuccessful!\n");
        exit(-1);
    }
    else if(pid == 0) {
        printf("Child starts\n");
        if(execl(argv[1] , argv[2],NULL) < 0) {
            printf("%s program not loaded using exec system call\n",argv[2]);
            exit(-1);
        }
    }
    else {
        wait(NULL);
        printf("Child Terminated\n");
        exit(0);
    }
}