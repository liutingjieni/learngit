#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int len,mid,i,top=0;
    char a[20],s[10];
    scanf("%s",a);
    len=strlen(a);
    mid=len/2-1;
    for(i=0;i<=mid;i++)
    {
        s[top++]=a[i];
    }
    if()
    while(top==0)
    {
        if(s[top]==a[i])
        {
            top--;
            i++;
        }       
        else
        {
            printf("NO");
            break;
        }
         
    }
    if(top==0)
    {
        printf("Yes");
    }
    return 0;
}
