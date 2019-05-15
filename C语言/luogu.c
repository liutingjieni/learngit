#include <stdio.h>

int a[10],book[10];
int n;

int dfs(int step)
{
    int i;
    if(n+1==step)
    {

        for(i=1;i<=n;i++)
        {
            printf("%d",a[i]);

        }
        printf("\n");
       /* int b,c,d;
        b=a[1]*100+a[2]*10+a[3];
        c=a[4]*100+a[5]*10+a[6];
        d=a[7]*100+a[8]*10+a[9];
        if(2*b==c&&4*b==d)
        {
            printf("%d%d%d  %d%d%d  %d%d%d",a[1],a[2],a[3],a[4],a[5],a[6],a[7],a[8],a[9]);
        }  
        return 0 ;      */
    }
    for(i=1;i<n;i++)
    {
        if(book[i]==0)
        {
            book[i]=1;
            a[step]=i;

            dfs(step+1);

            book[i]=0;
        }
    }
    return 0;
}

int main(int argc, char const *argv[])
{
    scanf("%d",&n);
    dfs(1);
    return 0;
}
