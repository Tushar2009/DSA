#include <bits/stdc++.h>
using namespace std;
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = 1;
    if (num[0] <= tar)
        dp[0][num[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= tar; target++)
        {
            int not_pick = dp[i - 1][target];
            int pick = 0;
            if (num[i] <= target)
            {
                pick = dp[i - 1][target - num[i]];
            }
            dp[i][target] = pick + not_pick;
        }
    }
    return dp[n - 1][tar];
}