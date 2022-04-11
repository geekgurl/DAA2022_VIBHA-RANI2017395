#include<iostream>
#include<algorithm>
using namespace std;
int KthSmallestElement(int a[],int n,int k)
{
    sort(a,a+n);
    return a[k-1];
}
int KthLargestElement(int a[],int n,int k)
{
    sort(a,a+n);
    return a[n-k];
} 
int main()
{
    int n;
    cin>> n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int ks,kl;
    cout<<"Enter the kth smallest element you want to print :"<<endl;
    cin>>ks;
    cout<<"Enter the kth largest you want to print: "<<endl;
    cin>>kl;
    int x=KthSmallestElement(a,n,ks);
    int y=KthLargestElement(a,n,kl);
    cout<<ks<<"th Smallest element is = "<<x<<endl;
    cout<<kl<<"th Largest element is  = "<<y<<endl;
}