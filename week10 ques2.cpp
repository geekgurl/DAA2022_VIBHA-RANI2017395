#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t, d;
    cin >> n;
    vector<pair<int, int>> tasks(n), helper(n);
    for (int i = 0; i < n; i++){
        cin >> t;
        tasks[i].first = t;
    }
    for (int i = 0; i < n; i++){
        cin >> d;
        tasks[i].second = d;
    }
    helper = tasks;

    sort(helper.begin(), helper.end(), [](pair<int, int>a , pair<int, int>b)
    {return a.second < b.second; });

    vector<int> selected;
    int time = 0, count = 0, index;

    for (int i = 0; i < n; i++)
    {
        if (time + helper[i].first <= helper[i].second)
        {
            index = find(tasks.begin(), tasks.end(), helper[i]) - tasks.begin();
            selected.push_back(index + 1);
            count++;
            time += helper[i].first;
        }
    }

    cout << "Max number of tasks = " << count << "\n";
    cout << "Selected task numbers : ";
    for (auto it : selected)
        cout << it << " ";
    return 0;
}