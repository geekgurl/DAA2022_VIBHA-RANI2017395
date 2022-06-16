#include<bits/stdc++.h>
using namespace std;

int minOperations(vector<int> &matrix, int i, int j){
    if(i == j) return 0;
    int k;
    int min = INT_MAX;
    int count;
    for(k=i ; k<j ; k++){
        count = minOperations(matrix, i, k) + minOperations(matrix, k+1, j) + matrix[i-1]*matrix[k]*matrix[j];

        if(count < min) min = count;
    }
    return min;
}

int main(){
    int n, a, b;
    cin>>n;
    vector<int> matrix(n+1);
    for(int i=0 ; i<n ; i++){
        cin>>a>>b;
        matrix[i] = a;
    }
    matrix[n] = b;
    cout<<minOperations(matrix, 1, n);
    return 0;
}