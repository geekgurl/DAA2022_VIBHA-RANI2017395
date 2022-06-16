#include <bits/stdc++.h>
using namespace std;

void mergeFiles(vector<int> files)
{
    int cost = 0;
    sort(files.begin(), files.end());

    for (int i = 1; i < files.size(); i++)
    {
        files[i] += files[i - 1];
        cost += files[i];
    }
    cout << cost << "\n";
}

int main()
{
    int n;
    cin >> n;
    vector<int> files(n);

    for (int i = 0; i < n; i++)
        cin >> files[i];
    mergeFiles(files);
    return 0;
}