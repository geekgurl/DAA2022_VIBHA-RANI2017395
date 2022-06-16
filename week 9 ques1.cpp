#include <bits/stdc++.h>
using namespace std;
void floydWarshall(vector<vector<int>> &graph, vector<vector<int>> &result){
    int n = graph.size();
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (result[i][k] == INT_MAX || result[k][j] == INT_MAX) 
                    continue;
                else
                    result[i][j] = min(result[i][j], result[i][k] + result[k][j]);
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    string s;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> s;
            if (s == "INF"){
                graph[i][j] = INT_MAX;
            } else {
                graph[i][j] = stoi(s);
            }
        }
    }
    vector<vector<int>> result = graph;
    floydWarshall(graph, result);
    cout<<"Shortest Distance Matrix: "<<endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (result[i][j] == INT_MAX)
                cout << "INF ";
            else
                cout << result[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}