#include <stdio.h>
#include <stdlib.h>

int main()
{  
    char *p=(char *)malloc(sizeof(char)*20);
    char *q=p;
    scanf("%s %s",p,q);
    printf("%x\n",p);
    printf("%x\n",q);
    printf("%x\n",*p);
    printf("%x\n",*q);
    printf("%s %s\n",p,q);
    int *a="Linux";
    printf("%x\n",a);
    printf("%x",*a);
    return 0;
}

