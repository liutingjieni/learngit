#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char s[20];
    char *p1,*p2;
    scanf("%s",s);
    p1=p2=s;
    while(*p1!='\0')
    {
        if(*p1=='*')
        {
            putchar(*p1);
        }
        p1++;
    }

    while(*p2!='\0')
    {
        if(*p2!='*')
        {
            putchar(*p2);
        }
        p2++;
    }
    return 0;
}
