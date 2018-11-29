#include <stdio.h>


int m[10][10],s[10][10];
void matrixmul(int p[],int n)
{
    int i,j,l,k;
    for(i=1;i<=n;++i)
        m[i][i]=1;
    for(l=2;l<=n;++l)
    {
        for(i=1;i<=n-l+1;i++)
        {
            j=i+l-1;
            m[i][j]=99999;
            for(k=i;k<=j-1;k++)
            {
                int q=m[i][k]+m[k+1][j]+p[i-1]*p[j]*p[k];
                if(q<m[i][j])
                {
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }    
}

void printOpt(int i,int j)
{
    if(i==j)
        printf(" A%d ",i);
    else{
        printf("(");
        printOpt(i,s[i][j]);
        printOpt(s[i][j]+1,j);
        printf(")");
    }    
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int i,p[n+1];
    for(i=0;i<=n;++i)
        scanf("%d",&p[i]);
    matrixmul(p,n);
    printOpt(1,n);
    printf("%d",m[1][n]);
    return 0;
}
