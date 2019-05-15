#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct a
{
    char *name;
    int num;
}A;

A * func(A *a)
{
    a=(A *)malloc(sizeof(A));
    strcpy(a->name,"XiyouLinuxGroup");
    a->num=2018;
    printf("%s\n",a->name);
    return a;
}

int main()
{
    A *a;
    a=func(a);
    //printf("%s %d\n",a->name,a->num);
    return 0;
}
