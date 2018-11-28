#include<stdio.h>
#include<stdlib.h>
void swap(int a[],int i,int j)
{
    int temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}
void print1(int a[],int n)
{
    int i;
    printf("\nArray :");
    for(i=0;i<n;i++){
        printf("%4d",a[i]);
    }
}
void quickSort(int a[],int n,int l,int h)
{
    int pivot=a[(l+h)/2];
    //printf("%d",pivot);
    int i=l,j=h;
   // while(i<=j){
        while(a[i]<pivot)
            i++;
        while(a[j]>pivot)
            j--;
        if(i<=j){
            swap(a,i,j);
            i++;
            j--;
        }
   // }
    if(l<j){
        quickSort(a,n,l,j);
    }
    if(i<h){
        quickSort(a,n,i,h);
    }
    print1(a,n);
}

void main()
{
    int n,a[100],x,i;
    printf("Enter the size of the array :");
    scanf("%d",&n);
    printf("Enter the elements :");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    print1(a,n);
    quickSort(a,n,0,n-1);
    print1(a,n);
}
