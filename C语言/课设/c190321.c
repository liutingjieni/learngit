#include <stdio.h>
int main(int argc, char const *argv[])
{
    char a;
    scanf("%c",&a);
    if(a>='a'&&a<='z')
    {
        printf("小写");
    }   
    else if(a>='A'&&a<='z')
    {
        printf("大写");
    }
    else if(a>='0'&&a<='9')
    {
        printf("数字")；
    }
    else
    {
        printf("其他");
    }
    

    return 0;
}
