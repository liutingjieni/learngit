#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int globVar=5;

int main()
{
    pid_t pid;
    int var=1,i;

    printf("Process Creation Study\n");
    pid=vfork();
    switch(pid)
    {
        case 0:
            i=3;
            while(i-->0)
            {
                printf("Child process is running\n");
                globVar++;
                var++;
                sleep(1);
            }
            printf("Child's globVar =%d,var=%d\n",globVar,var);
            break;
        case -1:
            perror("Process creation failed");
        default:
            i=5;
            while(i-->0)
            {
                printf("Parent process is running\n");
                globVar++;
                var++;
                sleep(1);
            }
            printf("Parent's globVar =%d,var=%d\n",globVar,var);
            exit(0);
    }

    return 0;
}

