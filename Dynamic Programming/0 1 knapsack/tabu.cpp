#include <bits/stdc++.h>
using namespace std;
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, 0));
    // base cases
    for (int w = weight[0]; w <= maxWeight; w++)
        dp[0][w] = value[0];

    // nested loops
    for (int i = 1; i < n; i++)
    {
        for (int w = 0; w <= maxWeight; w++)
        {
            // copy the reccurence
            int not_take = 0 + dp[i - 1][w];
            int take = INT_MIN;
            if (weight[i] <= w)
            {
                take = value[i] + dp[i - 1][w - weight[i]];
            }
            dp[i][w] = max(not_take, take);
        }
    }

    return dp[n - 1][maxWeight];
}