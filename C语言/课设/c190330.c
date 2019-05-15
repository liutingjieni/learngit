#include <stdio.h>

int n,m,p,q,min=99999999;
int a[51][51],book[51][51];
void dfs(int x,int y,int step)
{
    int next[4][2]={(0,1),(1,0)()}
}
int main(int argc, char const *argv[])
{
    int i,j,startx,starty;
    scanf("%d%d",&i,&j);
    for(i=1;i<n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
        }

    }

    scanf("%d%d%d%d",&startx,&starty,&p,&q);//读入起点和终点坐标

    book[startx][starty]=1;
    dfs(startx,starty,0);

    printf("%d",min);

    return 0;
}
