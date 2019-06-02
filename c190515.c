#include <stdio.h>
extern a;
void func()
{
	printf("a=%d\n",a);
}
int a=10;
int main()
{
	func();
	return 0;
}

