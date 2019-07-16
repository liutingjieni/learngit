#include <stdio.h>
#include <malloc.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/param.h>
#include <signal.h>
#include <syslog.h>

int main()
{
    int i;
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

    for(i=0;environ[i]!=NULL;i++)
    {
        printf("%s\n",environ[i]);
    }
    return 0;
}

