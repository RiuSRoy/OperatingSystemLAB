/* fork system call  */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

main()
{
    pid_t pid;
    int x = 5;
    pid = fork();
    if(pid < 0) {
        printf("Process creation unsuccessful!\n");
        exit(-1);
    }
    else if(pid == 0) {
        printf("Child Process\n");
        printf("Id of child process : %d\n",getpid());
        printf("Shared variable : %d\n",x);
        printf("Id of parent process : %d\n\n",getppid());
    }
    else {
        printf("Parent Process :\n");
        printf("Process ID : %d\n",getpid());
        printf("Shared variable : %d\n",x);
        printf("Id of the shell : %d\n\n",getppid());
    }
}