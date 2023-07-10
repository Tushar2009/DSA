#include <bits/stdc++.h>
using namespace std;
int f(int ind, int T, vector<int> &num, vector<vector<int>> &dp)
{
    if (ind == 0)
    {
        if (T % num[0] == 0)
            return T / num[0];
        return 1e9;
    }
    if (dp[ind][T] != -1)
        return dp[ind][T];
    int not_take = 0 + f(ind - 1, T, num, dp);
    int take = 1e9;
    if (num[ind] <= T)
    {
        take = 1 + f(ind, T - num[ind], num, dp);
    }
    return dp[ind][T] = min(take, not_take);
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    vector<vector<int>> dp(num.size(), vector<int>(x + 1, -1));
    int ans = f(num.size() - 1, x, num, dp);
    if (ans >= 1e9)
        return -1;
    return ans;
}