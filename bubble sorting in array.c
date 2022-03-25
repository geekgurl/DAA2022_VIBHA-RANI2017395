#include<stdio.h>
void bubble_sort(int[],int);
void main()
{
    int i,a[10],n;
    printf("enter the number of inputs:");
    scanf("%d",&n);
    printf("emter the elements of array:");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    bubble_sort(a,n);
    for(i=0;i<n;i++)
    {
        printf("%d",a[i]);  
    }
}
void bubble_sort(int a[],int n)
{
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(a[j]>a[j+1])
            {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }

    }
}