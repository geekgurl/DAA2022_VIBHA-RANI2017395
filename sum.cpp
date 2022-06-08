#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t, n;
    cin>>t;
    while(t != 0)
    {
        cin>>n;
        int arr[n], key, flag = 0;
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];
        cin>>key;
        sort(arr, arr + n);
        int l = 0, r = n-1;
        while(l<=r)
        {
            if(arr[l] + arr[r] == key)
            {
                cout<<arr[l]<<" "<<arr[r]<<endl;
                flag = 1;
                break;
            }
            else if(arr[l] + arr[r] > key)
                r--;
            else if(arr[l] + arr[r] < key)
                l++;
        }
        if(flag == 0)
            cout<<"No such elements Exist\n";
        t--;
    }
    return 0;
}