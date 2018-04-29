/* read */
// To read the given file and to display file contents.

#include<stdio.h>
#include<fcntl.h>

main(int argc,char* argv[])
{
    if(argc != 2) {
        printf("Usage : ./a.out <filename>");
        return 0;
    }
    int fd = open(argv[1] , O_RDONLY, 0444);
    if(fd < 0) {
        printf("File does not exist\n");
        exit(-1);
    }
    char buf[100];
    printf("Contents of file %s : \n" , argv[1]);
    while(read(fd, buf,sizeof(buf)) > 0) {
        printf("%s",buf);
    }
    close(fd);
}