#include <stdio.h>

int main()
{
    unsigned int a=10;
    int b=-20;
    printf("%x\n",a);
    printf("%d\n",a+b);
    printf("%u\n",a+b);
    if(a+b>0)
    {
        printf("a+b=%d\n",a+b);
    }
    if(a<b)
    {
        printf("*8");
    }
    return 0;
}

