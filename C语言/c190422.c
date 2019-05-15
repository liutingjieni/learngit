#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAME(n) x##n
#define PRINTVAL(y,...) printf("x"#y":"__VA_ARGS__)

typedef struct a
{
    char *name;
    int num;
}A;

A *func(A *b)
{
    b=(A *)malloc(sizeof(A));
    strcpy(b->name,"XIyouLinuxGroup");
    b->num=2018;
    
    printf("%s %d\n",b->name,b->num);
    return b;
}
int main()
{
    A *a;
    a=func(a);
}
