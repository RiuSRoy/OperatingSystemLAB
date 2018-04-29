#include<stdio.h>
#include<sys/stat.h>
#include<time.h>

int main(int argc,char* argv[])
{
    struct stat f;
    if(argc != 2) {
        printf("Usage : ./a.out <filename>");
        return 1;
    }
    if(stat(argv[1] , &f) < 0) {
        perror(argv[1]);
        exit(-1);
    }
    printf("User id : %d\n"  ,f.st_uid);
    printf("Group id : %d\n" , f.st_gid);
    printf("Block size : %d\n",f.st_blksize);
    printf("Blocks allocated : %d\n",f.st_blocks);
    printf("Inode no. : %d\n", f.st_ino);
    printf("Last accessed : %s\n" , ctime(&f.st_atime));
    printf("Last modified : %s\n",ctime(&f.st_mtime));
    printf("Time of last status change : %s\n",ctime(&f.st_ctime));
    printf("File size : %d bytes\n", f.st_size);
    printf("Identifier of device: %d\n",f.st_dev);
    printf("\tPermissions:\n");
    printf((S_ISDIR(f.st_mode) ? "d" : "-"));
    printf((f.st_mode & S_IRUSR) ? "r" : "-");
    printf((f.st_mode & S_IWUSR) ? "w" : "-");
    printf((f.st_mode & S_IXUSR) ? "x" : "-");
    printf((f.st_mode & S_IRGRP) ? "r" : "-");
    printf((f.st_mode & S_IWGRP) ? "w" : "-");
    printf((f.st_mode & S_IXGRP) ? "x" : "-");
    printf((f.st_mode & S_IROTH) ? "r" : "-");
    printf((f.st_mode & S_IWOTH) ? "w" : "-");
    printf((f.st_mode & S_IXOTH) ? "x" : "-");
    printf("\n");
}