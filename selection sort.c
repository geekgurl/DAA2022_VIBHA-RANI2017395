#include<stdio.h>
void selection_sort(int[],int);
void main()
{
    int i,n,a[10];
    printf("enter the limit :");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    selection_sort(a,n);
}

void selection_sort(int a[],int n)
{
    int i,j,temp,min;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[min])
            {
                min=j;
            }
        }
        temp=a[i];
        a[i]=a[min];
        a[min]=temp;
    }
    
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);
    }
}