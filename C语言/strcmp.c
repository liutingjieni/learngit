#include <stdio.h>
#include <string.h>

void str_cmp(char *p,char *q)
{
    int flag=0,len;
    len=strlen(p);
    if(strlen(p)==strlen(q))
    {
        while(*p++==*q++)
    {
        flag++; 
    }
    if(len==(flag-1))
    {
        printf("相等");
    }
    else
    {
        printf("不相等");
    }
    
    }
    
    else
    {
        printf("不相等");
    }
    
}
main()
{
    char a[20],b[20];
    int len;
    scanf("%s",a);
    scanf("%s",b);
    str_cmp(a,b);
}