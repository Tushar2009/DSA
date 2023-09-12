#include <bits/stdc++.h>
using namespace std;
int f(int ind, int buy, int cap, vector<int> &prices, vector<vector<vector<int>>> &dp)
{
    if (ind == prices.size())
        return 0;
    if (cap == 0)
        return 0;
    if (dp[ind][buy][cap] != -1)
        return dp[ind][buy][cap];
    int profit = 0;
    if (buy)
    {
        // for remembering the pattern basically when we buy the stock the amount is given so that's
        // why the -amount is there during buy
        profit = max(-prices[ind] + f(ind + 1, 0, cap, prices, dp), 0 + f(ind + 1, 1, cap, prices, dp));
    }
    else
    {
        // here the amount comes back sso the amount is taken as positive
        profit = max(prices[ind] + f(ind + 1, 1, cap - 1, prices, dp), 0 + f(ind + 1, 0, cap, prices, dp));
    }
    return dp[ind][buy][cap] = profit;
}
int maxProfit(vector<int> &prices, int n)
{
    // Write your code here
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return f(0, 1, 2, prices, dp);
}