#include<iostream>
using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t != 0)
    {
        int n;
        cin>>n;
        char arr[n], key, max = 'a';
        for(int i=0 ; i<n ; i++)
            cin>>arr[i];
        
        for(int i=0 ; i<n ; i++)
            if(arr[i]-97 > max-97)
                max = arr[i];
            
        int auxArr[(max-97)+1] = {0};

        for(int i=0 ;i<n ; i++)
            auxArr[arr[i]-97]++;

        max = max-97;
        int max2 = 0, index;
        for(int i=0 ; i<max+1 ; i++)
            if(auxArr[i] > max2)
            {
                max2 = auxArr[i];
                index = i;
            }
        if(max2 == 1)
            cout<<"No-Duplicate Present\n";
        else
        {
            char c = char(index+97);
            cout<<c<<" "<<max2<<"\n";
        }
     t--; 
    }
        return 0;
}