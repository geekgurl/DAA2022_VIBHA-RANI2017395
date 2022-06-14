#include <bits/stdc++.h>
using namespace std;

int minKey(int key[], bool vertices[], int v)
{
    // Initialize min value
    int min = INT_MAX, min_index;
 
    for (int i = 0; i < v; i++)
        if (vertices[i] == false && key[i] < min)
            min = key[i], min_index = i;
 
    return min_index;
}

void prim(vector<vector<int>> graph, int v)
{
    int node[v]; // array to store nodes of constructed Minimum spanning tree
    int key[v]; //key values to pick minimum weight edge
    bool vertices[v]; //represent the set of vertices includes in mst
    for(int i=0 ; i<v ; i++)
        key[i] = INT_MAX, vertices[i] = false;

    key[0] = 0;
    node[0] = -1;

    for(int j=0 ; j<v-1 ; j++){
        int u = minKey(key, vertices, v);
        vertices[u] = true;

        for(int k=0 ; k<v ; k++){
            if(graph[u][k] && vertices[k] == false && graph[u][k] < key[k])
                node[k] = u, key[k] = graph[u][k];
        }
    }
    int ans = 0;
    for (int i = 1; i < v; i++)
        ans += graph[i][node[i]];        

    cout<<"Minimm Spanning weight: "<<ans;
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
    prim(graph, v);
    return 0;
}