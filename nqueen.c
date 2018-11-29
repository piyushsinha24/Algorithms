#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int x[10];

int place(int k,int i)
{
	int j;
    for(j=1;j<=k-1;++j)
    {
        if(x[j]==i || abs(j-k)==abs(x[j]-i))
            return 0;
    }
    return 1;
}

void nqueen(int k,int n)
{
	int i, j;
    for(i=1;i<=n;++i)
    {
        if(place(k,i))
        {
            x[k]=i;
            if(k==n)
            {
                for(j=1;j<=n;++j)
                    printf("%d\t",x[j]);
                printf("\n");    
            }
            else nqueen(k+1,n);
        }
    }
}

int main(void)
{
    int n=4;
    nqueen(1,n);
}
