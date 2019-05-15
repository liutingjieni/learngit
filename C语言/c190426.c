#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct student
{
    char name[10];
    int  score[3];
    int  aver;
};
void sort(struct student s[])
{
    int i,j;
    struct  student t;//交换成绩的数组
    for(i=0;i<4;i++)
    {
        s[i].aver=(s[i].score[0]+s[i].score[1]+s[i].score[2])/3;
    }
    for(i=0;i<4;i++)//冒泡排序
    {
        for(j=0;j<4-i;j++)
        {
            if(s[j].aver>s[j+1].aver)
            {
                t=s[j];
                s[j]=s[j+1];
                s[j+1]=t;
            }
        }
    }
    printf("姓名\t语文\t数学\t英语\t平均分\n");
    for(i=0;i<4;i++)
    {
        printf("%s\t%d\t%d\t%d\t%d\n",s[i].name,s[i].score[0],s[i].score[1],s[i].score[2],s[i].aver);
    }
}
int main()
{ 
    int i;
    struct student s[4];
    for(i=0;i<4;i++)
    {
        scanf("%s",s[i].name);
        scanf("%d%d%d",&s[i].score[0],&s[i].score[1],&s[i].score[2]);
    }
    sort(s);

}

