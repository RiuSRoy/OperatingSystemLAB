//Simulate grep command using system call


#include<stdio.h>
#include<string.h>

main(int argc , char* argv[])
{
    if(argc != 3) {
        printf("Usage : ./a.out <filename> <pattern>");
        return 0;
    }
	char fn[10],pat[10],buf[200];
	FILE *fd;
	fd=fopen(argv[1] , "r");
    /* feof returns 0 only on EOF */
	while(!feof(fd))
	{
		fgets(buf,1000,fd); /*stops when either (n-1) characters
         are read, the newline character is read, or the end-of-file
         is reached, whichever comes first. */
		if(strstr(buf,argv[2])) {  //buf = cur line
            printf("%s",buf);
        }		  
	}
	fclose(fd);
}