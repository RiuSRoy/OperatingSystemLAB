/* generate 25 fib numbers and determine prime amongst them using pipe */

#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>

main()
{
    int pfd[2] , ar[25], br[25],i , j;
    if(pipe(pfd) < 0) {
        printf("Error in pipe\n"); 
        exit(-1);
    }
    pid_t pid = fork();
    if(pid < 0) {
        printf("Process creation unsuccessful\n"); 
        exit(-1);
    }
    else if(pid == 0) {
        printf("Child generates fib numbers : \n");
        int f1 = -1 , f2 = 1;
        for(i = 0;i < 25;++i) {
            ar[i] = f1 + f2;
            f1 = f2;
            f2 = ar[i]; 
            printf("%d ",ar[i]);
        }
        printf("\n");
        write(pfd[1] , ar , 25*sizeof(int));
    }
    else {
        wait(NULL);
        printf("\nParent process generates prime fib :\n");
        read(pfd[0] , br , 25*sizeof(int));
        for(i = 0; i < 25 ;++i) {
            int flag = 0;
            if(br[i] <= 1) 
                flag = 1;
            for(j = 2; j <= br[i]/2 ; ++j) {
                if(br[i]%j == 0) {
                    flag = 1;
                    break;
                }
            }
            if(!flag) {
                printf("%d ",br[i] );
            }
        }
        printf("\n");
    }
}

/* PIPES :
Pipes are unidirectional byte streams which connect the standard
output from one process into the standard input of another process.
A pipe is created using the system call pipe that returns a pair of file 
descriptors. The descriptor pfd[0] is used for reading and pfd[1] is used
for writing. Can be used only between parent and child processes. */