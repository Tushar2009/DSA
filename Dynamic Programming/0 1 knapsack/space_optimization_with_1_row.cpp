#include <bits/stdc++.h>
using namespace std;
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    vector<int> prev(maxWeight + 1, 0);
    // base cases
    for (int w = weight[0]; w <= maxWeight; w++)
        prev[w] = value[0];

    // nested loops
    for (int i = 1; i < n; i++)
    {
        for (int w = maxWeight; w >= 0; w--)
        {
            // copy the reccurence
            int not_take = 0 + prev[w];
            int take = INT_MIN;
            if (weight[i] <= w)
            {
                take = value[i] + prev[w - weight[i]];
            }
            prev[w] = max(not_take, take);
        }
    }

    return prev[maxWeight];
}