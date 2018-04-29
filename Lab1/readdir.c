/* list directory contents  */


#include<stdio.h>
#include<dirent.h>

int main(int argc,char* argv[])
{
    struct dirent* dir;
    DIR* dname = opendir(argv[1]);
    if(dname == NULL) {
        perror(argv[1]);
        return 0;
    }
    while(dir = readdir(dname)) {
        printf("%s\n",dir->d_name);
    }
    closedir(dname);
}