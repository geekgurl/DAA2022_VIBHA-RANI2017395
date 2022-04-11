#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int key;
    int count=0;
    cin>>key;
    for(int i=0;i<n;i++)
    {
        if(key==a[i])
        {
            cout<<"KEY element found"<<endl;
            count++;
            break;
        }
        else
        {
            count++;
        }
    }
    cout<<"NUmber of comparisons = "<<count<<endl;
}