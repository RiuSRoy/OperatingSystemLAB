/* list current dirctory contents  */
// To simulate ls command using UNIX system calls.

#include<stdio.h>
#include<dirent.h>

// filter (3rd argument of scandir)
int file_select(const struct dirent *entry)
{
   return strcmp(entry->d_name, ".c");
}

main(int argc,char*argv[])
{
    struct dirent** dir;
    char path[100];
    getcwd(path);
    int n , i;
    n = scandir(path , &dir , file_select(&dir) , alphasort);
    if(n < 0) {
        printf("Error\n");
    }
    else {
        for(i = 0;i < n;++i) {
            if(dir[i]->d_name[0] != '.') {
                printf("%s ",dir[i]->d_name);
            }
        }
    }
}

