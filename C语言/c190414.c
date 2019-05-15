#include <stdio.h>
#include <string.h>
int main()
{
    int c;
    memcpy(&c,"l",4);
    printf("%d\n",c);
    return 0;
}
