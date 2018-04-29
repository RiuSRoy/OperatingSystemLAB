/* wait system call  */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>

main()
{
    pid_t pid;
    int i;
    pid = fork();
    if(pid < 0) {
        printf("Process creation unsuccessful!\n");
        exit(-1);
    }
    else if(pid == 0) {
        printf("\n@@@@@@@@@@@ Child Starts @@@@@@@@@@@\n");
        printf("Odd Nos : \n");
        for(i = 1; i <= 10 ; i += 2) {
            printf("%d ",i);
        }
        printf("\n@@@@@@@@@@@ Child Ends @@@@@@@@@@@\n\n");
    }
    else {
        wait(NULL);
        printf("\n@@@@@@@@@@@ Parent Starts @@@@@@@@@@@\n");
        printf("Even Nos : \n");
        for(i = 2; i <= 10 ; i += 2) {
            printf("%d ",i);
        }
        printf("\n@@@@@@@@@@@ Parent Ends @@@@@@@@@@@\n");
    }
}