#include <bits/stdc++.h>
using namespace std;
int f(int ind, int buy, vector<int> &prices, int fee, vector<vector<int>> &dp)
{
    if (ind == prices.size())
        return 0;
    if (dp[ind][buy] != -1)
        return dp[ind][buy];
    if (buy)
    {
        return dp[ind][buy] = max(-prices[ind] + f(ind + 1, 0, prices, fee, dp), 0 + f(ind + 1, 1, prices, fee, dp));
    }
    else
    {
        return dp[ind][buy] = max((prices[ind] - fee) + f(ind + 1, 1, prices, fee, dp), 0 + f(ind + 1, 0, prices, fee, dp));
    }
}
int maximumProfit(int n, int fee, vector<int> &prices)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return f(0, 1, prices, fee, dp);
}
