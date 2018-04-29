/* open a source file , create a dest file and copy the source code from the former to the latter  */

#include<stdio.h>
#include<fcntl.h>

main(int argc,char* argv[])
{
    if(argc != 3) {
        printf("Usage : ./a.out <source file> <dest file>\n");
        return 0;
    }
    int fd = open(argv[1] , O_RDONLY);
    if(fd < 0) {
        printf("Source file not found\n");
        exit(-1);
    }
    int dest = creat(argv[2] , 0644);
    if(dest < 0) {
        printf("Destination File creation problem\n");
        exit(-1);
    }
    char buf[1024];
    int nread;
    while((nread = read(fd , buf , 1024)) > 0) {
        if(write(dest , buf , nread) == -1) {
            exit(-1);
        }         
    }
    close(fd);
    close(dest);    
}