#include<bits/stdc++.h>
using namespace std;

bool partition(vector<int> sets, int n){
    int sum = 0;
    for(int i=0 ; i<n ; i++) sum += sets[i];

    if(sum%2 != 0) return false;

    bool part[sum/2 + 1][n+1];

    for(int i=0 ; i<=n ; i++) part[0][i] = true;

    for(int i= 1 ; i<= sum/2 ; i++) part[i][0] = false;

    for(int i=1 ; i<=sum/2 ; i++){
        for(int j=1 ; j<=n ; j++){
            part[i][j] = part[i][j-1];
            if(i >= sets[j-1])
                part[i][j] = part[i][j] || part[i - sets[j-1]][j-1];
        }
    }
    return part[sum/2][n];
}

int main(){
    int n, val;
    cin>>n;
    vector<int> sets;
    for(int i=0 ; i<n ; i++){
        cin>>val;
        sets.push_back(val);
    }

    bool check = partition(sets, n);
    check == true ? cout<<"YES" : cout<<"NO";
    return 0;
}