#include <bits/stdc++.h>
using namespace std;
long f(int ind, int T, int coin[], vector<vector<long>> &dp)
{
    if (ind == 0)
    {
        if (T % coin[0] == 0)
            return 1;
        else
            return 0;
    }
    if (dp[ind][T] != -1)
        return dp[ind][T];
    long not_take = f(ind - 1, T, coin, dp);
    long take = 0;
    if (coin[ind] <= T)
    {
        take = f(ind, T - coin[ind], coin, dp);
    }
    return dp[ind][T] = not_take + take;
}
long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here
    vector<vector<long>> dp(n, vector<long>(value + 1, -1));
    return f(n - 1, value, denominations, dp);
}