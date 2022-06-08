#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t != 0)
    {
    int n, m, i=0, j=0;
    cin>>n;
    int arr1[n];
    for(int i=0 ; i<n ; i++)
        cin>>arr1[i];   
    cin>>m;
    int arr2[m];
    for(int i=0 ; i<m ; i++)
        cin>>arr2[i];  
    while(i<n && j<m)
    {
        if(arr1[i] == arr2[j])
            cout<<arr1[i++]<<" "<<arr2[j]<<endl;
        else if(arr1[i] > arr2[j])
            j++;
        else        i++;
    } 
    t--;
    }
    return 0;
}