#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
    pid_t pid;


    printf("Process Creation Study\n");
    pid=fork();
    switch(pid)
    {
        case 0:
            while(1)
            {
                printf("A background process is running ,pid is %d,Parentpid is %d\n",getpid(),getppid());
                sleep(3);
            }
        case -1:
            perror("Process creation failed\n");
            exit(-1);
        default:
            printf("Parent process is running ,Parentpid is %d\n",getpid());
            exit(0);
    }

    return 0;
}

