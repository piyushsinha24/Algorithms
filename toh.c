#include <stdio.h>

void toh(int n,char a,char b,char c)
{
    if(n>0)
    {
        toh(n-1,a,c,b);
        printf("%d : %c -> %c\n",n,a,c);
        toh(n-1,b,a,c);
    }
}

int main(void)
{
    toh(3,'A','B','C');
}