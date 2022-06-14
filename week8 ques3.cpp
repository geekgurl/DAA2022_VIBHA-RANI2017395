#include<bits/stdc++.h>
using namespace std;

int find(vector<bool> visited, vector<int> weight, int v)
{
    int index = -1;
    int maxWeight = INT_MIN;

    for(int i=0 ; i<v ; i++){
        if(visited[i] == false && weight[i] > maxWeight){
            maxWeight = weight[i];
            index = i;
        }
    }
    return index;
}

int maxSpanning(vector<vector<int>> graph, int v)
{
    vector<bool> visited(v, false);
    vector<int>weight(v, INT_MIN);
    int nodes[v];
    weight[0] = INT_MAX;
    nodes[0] = -1;
    for(int i=0 ; i<v-1 ; i++){
        int maxIndex = find(visited, weight, v);
        visited[maxIndex] = true;
        for(int j=0 ; j<v ; j++){
            if(graph[j][maxIndex] != 0 && visited[j] == false)
            {
                if(graph[j][maxIndex] > weight[j]){
                    weight[j] = graph[j][maxIndex];
                    nodes[j] = maxIndex;
                }
            }
        }
    }
    int ans = 0;
    for(int i=1 ; i<v ; i++){
        ans += graph[i][nodes[i]];
    }
    return ans;
}

int main()
{
    int v, i, j, val;
    cin >> v;
    vector<vector<int>> graph(v, vector<int>(v, 0));
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            cin >> val;
            graph[i][j] = val;
        }
    }
    cout<<"Maximum Spanning Weight: "<<maxSpanning(graph, v);
    return 0;
}