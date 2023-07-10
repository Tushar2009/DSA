#include <bits/stdc++.h>
using namespace std;
int f(int ind, int S, vector<int> &num, vector<vector<int>> &dp)
{
    if (S == 0)
        return 1;
    if (ind == 0)
    {
        return (num[0] == S);
    }
    if (dp[ind][S] != -1)
        return dp[ind][S];

    int not_pick = f(ind - 1, S, num, dp);
    int pick = 0;
    if (num[ind] <= S)
    {
        pick = f(ind - 1, S - num[ind], num, dp);
    }
    return dp[ind][S] = pick + not_pick;
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return f(n - 1, tar, num, dp);
}
