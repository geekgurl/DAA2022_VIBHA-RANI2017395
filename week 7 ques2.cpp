#include<bits/stdc++.h>
using namespace std;

void bellman_ford(unordered_map<int, vector<pair<int, int>>> graph, int src, vector<int> &minPath, set<int> &visited)
{
    vector<int> parent(graph.size() + 1, -1);
    int temp = src;
    pair<int, int> neighbor;

    while (visited.size() != graph.size())
    {
        for (int i = 1; i <= graph.size(); i++)
        {
            if (minPath[i] < INT_MAX && visited.find(i) == visited.end())
            {
                temp = i;
            }
        }
        visited.insert(temp);

        for (int i = 0; i < graph[temp].size(); i++)
        {
            neighbor = graph[temp][i];
            if (minPath[neighbor.first] > minPath[temp] + neighbor.second)
            {
                minPath[neighbor.first] = minPath[temp] + neighbor.second;
                parent[neighbor.first] = temp;
            }
        }
    }

    int dest;
    for (int i = 1; i < graph.size() + 2; i++)
    {
        if (parent[i] != -1)
        {
            dest = i;
            while (parent[dest] != -1)
            {
                cout << dest << " ";
                dest = parent[dest];
            }
        }
        cout << src << ": " << minPath[i] << endl;
    }
}

int main()
{
    unordered_map<int, vector<pair<int, int>>> graph;
    int n, val, src;
    cin >> n;
    vector<int> minPath(n + 1, INT_MAX);
    set<int> visited;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> val;
            if (val != 0)
                graph[i].push_back({j, val});
        }
    }

    cin >> src;
    minPath[src] = 0;

    bellman_ford(graph, src, minPath, visited);

    return 0;
}