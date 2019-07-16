#include <stdio.h>

int main(int argc, char const *argv[])
{
    int nums[3][3]={1,2,3,4,5,6,7,8,9};
    printf("%d\n",nums[1][-2]);
    printf("%d\n",(-1)[nums][0]); 
    printf("%d\n",-1[nums][0]);
    return 0;
}