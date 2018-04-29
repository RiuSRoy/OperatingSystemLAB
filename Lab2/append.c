/* append  */
// To append content to an existing file.

#include<stdio.h>
#include<fcntl.h>

main(int argc,char* argv[])
{
    if(argc != 2) {
        printf("Usage : ./a.out <filename>");
        return 0;
    }
    char buf[100];
    int fd = open(argv[1] , O_APPEND|O_WRONLY , 0644);
    if(fd < 0) {
        perror(argv[1]);
        exit(-1);
    }
    while(read(0,buf,sizeof(buf)) > 0) {
        int len = strlen(buf);
        write(fd , buf , len);
    }
    close(fd);
}