#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    int arr[n], key;
    cout<<"Enter the elements: ";
    for(int i=0 ; i<n ; i++)
        cin>>arr[i];
    cout<<"Enter the key element: ";
    cin>>key;
    int m = sqrt(n), i=0;
    while(arr[m] <= key && m<n)
    {
        i=m;
        m = m+sqrt(n);
        if(m>n-1)
            m=n;
    }
    for(int x=i ; x<m ; x++)
        if(arr[x] == key)
            cout<<x;

    return 0;
}