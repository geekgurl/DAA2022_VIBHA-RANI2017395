#include<bits/stdc++.h>
using namespace std;

int check(int i, vector<int> node)
{
    while(node[i] != i) i = node[i];
    return i;
}

void Union(int i, int j, vector<int> &node)
{
    int x = check(i, node);
    int y = check(j, node);
    node[x] = y;
}


void kruskalMST(vector<vector<int>> graph, int v)
{
    vector<int> node(v);
    int minWeight = 0;
    for(int i=0 ; i<v ; i++)  node[i] = i;

    int edges = 0;
    while(edges <v-1){
        int min = INT_MAX, a = -1, b = -1;
        for(int i=0 ; i<v ; i++){
            for(int j=0 ; j<v ; j++){
                if(check(i, node) != check(j, node) && graph[i][j] < min){
                    min = graph[i][j];
                    a = i;
                    b = j;
                }
            }
        }
    Union(a, b, node);
    edges++;
    minWeight += min;
    }
    cout<<"Minimum Spanning wieght: "<<minWeight;
}

int main()
{
    int v, i, j, val;
    cin >> v;
    vector<vector<int>> graph(v, vector<int>(v, 0));
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            cin>>val;
            if(val == 0) graph[i][j] = INT_MAX;
            else graph[i][j] = val;
        }
    }
    kruskalMST(graph, v);
    return 0;
}