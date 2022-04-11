#include<iostream>
using namespace std;
int binarysearch(int a[],int l,int h,int key)
{
    if(h>=l)
    {
        int mid=(l+(h))/2;
        if(a[mid]==key)
        {
            return mid;
        }
        if(a[mid]>key)
        {
            return binarysearch(a,l,mid-1,key);
        }
        else
        {
            return binarysearch(a,mid+1,h,key);
        }
    }
    return -1;
}
int main()
{
    int low,high,mid,n,a[20],i,key,found;
    cout<<"enter the size of array :"<<endl;
    cin>>n;
    cout<<"enter the elements of array :"<<endl;;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    cout<<"enter the element you wanted to search :"<<endl;
    cin>>key;
    int result=binarysearch(a,0,n-1,key);
    if(result==-1)
    {
        cout<<"Element not found"<<endl;
    }
    else
    {
        cout<<"Element found at index = "<< result+1 << endl;
    }
}