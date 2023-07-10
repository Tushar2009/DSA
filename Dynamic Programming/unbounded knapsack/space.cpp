#include <bits/stdc++.h>
using namespace std;
int unboundedKnapsack(int n, int wt, vector<int> &val, vector<int> &weight)
{
    // Write Your Code Here.
    // vector<vector<int>> dp(n,vector<int>(wt+1,0));
    vector<int> prev(wt + 1, 0), curr(wt + 1, 0);
    for (int w = 0; w <= wt; w++)
    {
        prev[w] = (int)(w / weight[0]) * val[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= wt; w++)
        {
            int not_take = 0 + prev[w];
            int take = INT_MIN;
            if (weight[i] <= w)
            {
                take = val[i] + curr[w - weight[i]];
            }
            curr[w] = max(not_take, take);
        }
        prev = curr;
    }
    return prev[wt];
}