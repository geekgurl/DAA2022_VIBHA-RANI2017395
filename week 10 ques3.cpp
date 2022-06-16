#include<bits/stdc++.h>
using namespace std;

void findMajority(vector<int> &v, int n){
    int cnt = 0;
    int index = -1;
    for(int i=0 ; i<n ; i++){
        int c = 0;
        for(int j=0 ; j<n ; j++){
            if(v[i] == v[j]) c++;
        }
        if(c > cnt){
            cnt = c;
            index = i;
        }
    }
    if(cnt > n/2) cout<<"yes"<<endl;
    else cout<<"no"<<endl;
}

int findMedian(vector<int> &v, int n){
    sort(v.begin(), v.end());
    if(n%2 != 0) return v[n/2];

    return (v[(n-1)/2] + v[n/2])/2.0;
}

int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0 ; i<n ; i++)    cin>>v[i];

    findMajority(v, n);
    cout<<findMedian(v, n)<<endl;
    return 0;
}