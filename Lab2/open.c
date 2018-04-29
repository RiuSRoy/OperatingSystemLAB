/* open system call  */
// To create a file and to write contents.

#include<stdio.h>
#include<fcntl.h>

main(int argc , char* argv[])
{
    if(argc != 2) {
        printf("Usage : ./a.out <filename>");
        return 0;
    }
    char buf[100];
    int fd = open(argv[1] , O_WRONLY|O_CREAT|O_TRUNC , 0644); //file descriptor
    if(fd < 0) {
        printf("File creation problem\n");
        exit(-1);
    }
    while(read(0, buf , sizeof(buf)) > 0) {  //read = 0 => EOF
        int len = strlen(buf);
        write(fd , buf , len);
    } 
    close(fd);
}



/* The parameter flags must include one of the following access modes:
 O_RDONLY,
 O_WRONLY,
 O_RDWR. These request opening the file
  read-only, write-only, or read/write, respectively.

The file creation flags are O_CREAT, O_EXCL, O_NOCTTY, and O_TRUNC. */