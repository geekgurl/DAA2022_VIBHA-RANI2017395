#include<bits/stdc++.h>
#include<climits>
using namespace std;

int shortestpath(vector<vector<int>> graph, int src, int dest, int k, int n)
{
    if(k == 0 && src == dest) return 0;
    if(k == 1 && graph[src][dest] != INT_MAX) return graph[src][dest];
    if(k <= 0) return INT_MAX;

    int res = INT_MAX;
    for(int i=0 ; i<n ; i++){
        if(graph[src][i] != INT_MAX && src != i && dest != i){
            int ans = shortestpath(graph, i, dest, k-1, n);
            if(ans != INT_MAX)  res = min(res, graph[src][i] + ans);
        }
    }
    return res;
}

int main()
{
    int n, val, src, dest, k;
    cin >> n;
    vector<vector<int>> graph(n,vector<int>(n,0));
    int i, j;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            cin>>val;
            if(val == 0 && i != j) graph[i][j] = INT_MAX;
            else graph[i][j] = val;
        }
    }

    cin>>src>>dest>>k;
    cout<<"Weight of Shortest Path from ("<<src<<","<<dest<<") with "<<k<<" edges : "<<shortestpath(graph, src-1, dest-1, k, n);
    return 0;
}