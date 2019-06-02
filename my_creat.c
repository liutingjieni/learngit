#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
int main(int argc,char **argv)
{
    int fd;
    if((fd=open("example_62.c",O_CREAT|O_EXCL,S_IRUSR|S_IWUSR))==-1)
    {
        if((fd=creat("example_62.c",S_IRWXU))==-1)
        {
            printf("##");
            perror("open");
          //  printf("open:%s  with error:%d\n",strerror(errno),errno);
            exit(1);
        }
        else
        {
            printf("creat fle success\n");
        }

        
    }
    close(fd);
    return 0;
}

