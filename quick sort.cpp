#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void printarray(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
}
int partition(int a[],int low,int high)
{
    int count;
    int pivot =a[high];
    int i=low-1;
    for(int j=low;j<high;j++)
    {
        if(a[j]<=pivot)
        {
            i++;
            swap(&a[i],&a[j]);
        }
        count++;
    }
    swap(&a[i+1],&a[high]);
    return i+1;
}
int quicksort(int a[],int low,int high,int count)
{
    if(low<high)
    {
        int pi=partition(a,low,high);
        quicksort(a,low,pi-1,count++);
        quicksort(a,pi+1,high,count++);
    }
    return count;
}
int main()
{
    int n;
    cout<<"Enter size of array :"<<endl;
    cin>>n;
    int a[n];
    cout<<"Enter elements of array: "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"Unsorted array = "<<endl;;
    printarray(a,n);
    int count=0;
    int x=quicksort(a,0,n-1,count);
    cout<<"Sorted array = "<<endl;
    printarray(a,n);
    cout<<"count="<<x<<endl;
}