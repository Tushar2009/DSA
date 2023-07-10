#include <bits/stdc++.h>
using namespace std;
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(num.size(), vector<int>(x + 1, 0));
    for (int T = 0; T <= x; T++)
    {
        if (T % num[0] == 0)
            dp[0][T] = T / num[0];
        else
            dp[0][T] = 1e9;
    }
    for (int i = 1; i < n; i++)
    {
        for (int T = 0; T <= x; T++)
        {
            int not_take = 0 + dp[i - 1][T];
            int take = 1e9;
            if (num[i] <= T)
            {
                take = 1 + dp[i][T - num[i]];
            }
            dp[i][T] = min(take, not_take);
        }
    }
    int ans = dp[n - 1][x];
    if (ans >= 1e9)
        return -1;
    return ans;
}