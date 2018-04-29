/* determine no of users logged in using pipe */

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
    int pfd[2];
    pipe(pfd);
    if(!fork()) {
        close(1) ;  //free stnd o/p to redirect it to the pipe
        close(pfd[0]);  // close reading end        
        dup(pfd[1]) ; //make a copy of write end of pipe        
        execlp("who" , "who" , NULL);
    }
    else {
        close(0) ;  //free stnd i/p
        close(pfd[1]); //let parent write into pipe        
        dup(pfd[0]) ; //make a copy of read end of pipe        
        execlp("wc", "wc" , "-l", NULL); 
    }
}

/* If execl() is successful, nothing after it in the original
 program runs, since it replaces the contents of the process 
 with the program you ask it to run.*/