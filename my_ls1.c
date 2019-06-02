#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <dirent.h>
#include <grp.h>
#include <pwd.h>
#define PARAM_NONE 0
#define PARAM_A    1
#define PARAM_L    2
#define MAXROWLEN  80

int main()
{
    for(i=1;i<argc;i++)
    {
        if(argv[i][0]='-')
        {
            for(j=1;j<strlen(argv[i]);j++,k++)
            {
                param[k]=agrv[i][j];
            }
            num++;
        }
    }


    return 0;
}

