#include<iostream>
using namespace std;
void printarray(int a[],int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<a[i]<<endl;
    }
}
void merge(int a[],int l,int mid,int r)
{
    int n1=mid-l+1;
    int n2=r-mid;
    int l1[n1],m[n2];
    for(int i=0;i<n1;i++)
    {
        l1[i]=a[l+i];
    }
    for(int j=0;j<n2;j++)
    {
        m[j]=a[mid+1+j];
    }
    int i,j,k;
    i=0;
    j=0;
    k=l;
    while(i<n1 && j<n2)
    {
        if(l1[i]<m[j])
        {
            a[k]=l1[i];
            i++;
        }
        else
        {
            a[k]=m[j];
            j++;
        }
        k++;
    }
    while(i<n1)
    {
        a[k]=l1[i];
        i++;
        k++;
    }
    while(j<n2)
    {
        a[k]=m[j];
        j++;
        k++;
    }
}
int  mergesort(int a[],int l,int r,int count)
{
    if(l<r)
    {
        int m=(l+r)/2;
        mergesort(a,l,m,count++);
        mergesort(a,m+1,r,count++);
        merge(a,l,m,r);
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
    int x=mergesort(a,0,n-1,count);
    cout<<"Sorted array = "<<endl;
    printarray(a,n);
    cout<<"Count="<<count<<endl;
}