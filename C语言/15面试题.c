#include <stdio.h>
//#include <syslib.h>
#include <string.h>

int main()
{
    int c;
    memcpy(&c,"linux",4);
    printf("%p\n","linux");
    printf("%d\n",c);
    return 0;
}

