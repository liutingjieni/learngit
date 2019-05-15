#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define NAME(n) x##n
#define PRINTVAL(y,...) printf("x"#y":"__VA_ARGS__)
int main()
{
    int NAME(1);
    short *NAME(2)=(short *)&NAME(1);
    char  *NAME(3)=(char  *)&NAME(1);
    NAME(1)=0x12345678;
    *NAME(2)=0x71b1;
    PRINTVAL(1,"%x\n",NAME(1));
    PRINTVAL(2,"%x\n",*NAME(2));
    PRINTVAL(3,"%x\n",*NAME(3));
}
