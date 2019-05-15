//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>

char * my_strcpy(char*p,char a[])
{
    while(*p++=*a++);
     
}

int main()
{
    char a[10];
    scanf("%s",a);
    //puts(a);
    char *p=a;
    my_strcpy(p,a);
    printf("%s\n",p);
}
