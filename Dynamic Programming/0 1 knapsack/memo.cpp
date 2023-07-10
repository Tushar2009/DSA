#include <bits/stdc++.h>
using namespace std;
int f(int ind, int w, vector<int> value, vector<int> weight, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (weight[0] <= w)
            return value[0];
        return 0;
    }
    if (dp[ind][w] != -1)
        return dp[ind][w];

    int not_take = 0 + f(ind - 1, w, value, weight, dp);
    int take = INT_MIN;
    if (weight[ind] <= w)
    {
        take = value[ind] + f(ind - 1, w - weight[ind], value, weight, dp);
    }
    return dp[ind][w] = max(not_take, take);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight)
{
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(maxWeight + 1, -1));

    return f(n - 1, maxWeight, value, weight, dp);
}