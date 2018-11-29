#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int max,min,arr[]={2,5,3,6,7};

void MaxMin(int i,int j)
{
    if(i==j)
    {
        max=arr[i];
        min=arr[i];
       // printf("here1\n");
    }
    else if(i==j-1)
    {
        //printf("here2\n");
        if(arr[i]>arr[j])
        {
            max=arr[i];
            min=arr[j];
            
        }
        else{
            max=arr[j];
            min=arr[i];
        }
    }
    else{
        //printf("here3\n");
        int mid=(i+j)/2;
        MaxMin(i,mid);
        int max1=max,min1=min;
        MaxMin(mid+1,j);
        if(max1>max)
            max=max1;
        if(min1<min)
            min=min1; 
       // printf("%d %d\n",max,min);       
    }
}

int main(int argc, char const *argv[])
{
    max=min=arr[0];
    MaxMin(0,4);
    printf("Max : %d, Min : %d",max,min);
    return 0;
}
