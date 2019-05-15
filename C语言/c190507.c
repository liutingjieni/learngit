#include <stdio.h>
#include <string.h>
void func(char *p)
{
    printf("%s",p);
    strcpy(p,"I love xiyoulinux");

}

int main()
{
    char a[20]="L LOVE";
    char *s=a;
    func(s);
    printf("%s",a);
    printf("%s",s);
}
