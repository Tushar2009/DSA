#include <bits/stdc++.h>
using namespace std;
int f(int ind, int w, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        return (int)(w / wt[0]) * val[0];
    }
    if (dp[ind][w] != -1)
        return dp[ind][w];
    int not_take = 0 + f(ind - 1, w, val, wt, dp);
    int take = INT_MIN;
    if (wt[ind] <= w)
    {
        take = val[ind] + f(ind, w - wt[ind], val, wt, dp);
    }
    return dp[ind][w] = max(not_take, take);
}
int unboundedKnapsack(int n, int w, vector<int> &val, vector<int> &wt)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w + 1, -1));
    return f(n - 1, w, val, wt, dp);
}