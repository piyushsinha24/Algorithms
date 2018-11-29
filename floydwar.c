#include <stdio.h>
#include <stdlib.h>

int p[10][10],d[10][10];

void apsp(int i,int j)
{
    if(i==j)
        printf("%d ",i);
    else if(p[i][j]==-1)
    {
        printf("There is no path between %d and %d\n",i,j);
        exit(0);
    }
    else{
        apsp(i,p[i][j]);
        printf("%d ",j);
    }
}
void floyd(int n)
{
    for(int k=1;k<=n;++k)
    {
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                if(d[i][j]>d[i][k]+d[k][j])
                {
                    d[i][j]=d[i][k]+d[k][j];
                    p[i][j]=p[k][j];
                }
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)
            printf("%d\t",d[i][j]);
        printf("\n");    
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)
        {
            //apsp(i,j);
            printf("%d\t",p[i][j]);
        }
        printf("\n");
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)
        {
            apsp(i,j);
            printf("\n");
        }
        //printf("\n");
    }
}



int main(void)
{
	int n;
	scanf("%d",&n);	
	for(int i=1;i<=n;++i)
	{
		for(int j=1;j<=n;++j)
		{	scanf("%d",&d[i][j]);
        }        
	}
    for(int i=1;i<=n;++i)
    {
        for(int j=1;j<=n;++j)
            scanf("%d",&p[i][j]);
    }	
	floyd(n);

}