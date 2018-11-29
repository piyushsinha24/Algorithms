#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int x[10],m,n,graph[10][10];

void next(int k)
{
    int j;
    while(1)
    {
        x[k]=(x[k]+1)%(m+1);
        if(x[k]==0) return;
        for(j=1;j<=n;j++)
        {
            if(graph[k][j] && x[k]==x[j])   break;
        }
        if(j==n+1)  return;
    }
}

void mcolor(int k)
{
    while(1)
    {
        next(k);
        if(x[k]==0) return;
        if(k==n)
        {
            for(int j=1;j<=n;++j)
                printf("%d\t",x[j]);
            printf("\n");    
        }
        else    mcolor(k+1);
    }
}

int main(void)
{
    m=2,n=4;
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;j++)
            scanf("%d",&graph[i][j]);
    }
    mcolor(1);
}