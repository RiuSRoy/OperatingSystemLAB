#include<stdio.h>
#include<fcntl.h>


int main(int argc,char* argv[])
{
    if(argc != 2) {
        printf("Usage : ./a.out <filename>\n");
        return 0;
    }
    int fd = open(argv[1] , O_RDONLY);
    if(fd < 0) {
        perror(argv[1]);
        return 0;
    }
    close(fd);
    unlink(argv[1]);
}