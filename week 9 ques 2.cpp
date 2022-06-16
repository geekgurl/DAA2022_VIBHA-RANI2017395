#include <bits/stdc++.h>
using namespace std;
struct Item {
    int value, weight;
};

bool cmp(struct Item a, struct Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;
    return r1 > r2;
}
double fractionalKnapsack(int W, vector<Item> &arr, int n)
{
    sort(arr.begin(), arr.end(), cmp);

 
    double finalvalue = 0.0; 
    for (int i = 0; i < n; i++) {
 
        if (arr[i].weight <= W) {
            W -= arr[i].weight;
            finalvalue += arr[i].value;
        }
 
        else {
            finalvalue
                += arr[i].value
                   * ((double)W / (double)arr[i].weight);
            break;
        }
    }
    return finalvalue;
}
 
// Driver code
int main()
{
    int n, W, val;
    cin>>n;
    vector<Item> arr(n);
    for(int i=0 ; i<n ; i++){
        cin>>val;
        arr[i].weight = val;
    }
    for(int i=0 ; i<n ; i++) {
        cin>>val;
        arr[i].value = val;
    }
    cin>>W;
    cout << "Maximum value = "
         << fractionalKnapsack(W, arr, n);
    return 0;
}