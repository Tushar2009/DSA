#include <bits/stdc++.h>
using namespace std;
int minSubsetSumDifference(vector<int> &arr, int n)
{
    // Write your code here.
    int total_sum = 0;
    for (int i = 0; i < n; i++)
        total_sum += arr[i];
    int k = total_sum;
    // subset sum
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int i = 0; i < n; i++)
        dp[i][0] = true;
    if (arr[0] <= k)
        dp[0][arr[0]] = true;
    for (int i = 1; i < n; i++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool not_take = dp[i - 1][target];
            bool take = false;
            if (arr[i] <= target)
            {
                take = dp[i - 1][target - arr[i]];
            }
            dp[i][target] = not_take | take;
        }
    }

    // dp[n-1][col-> 0....total_sum]
    int mini = 1e9;
    for (int s1 = 0; s1 <= total_sum / 2; s1++)
    {
        if (dp[n - 1][s1] == true)
        {
            int s2 = total_sum - s1;
            mini = min(mini, abs(s1 - s2));
        }
    }
    return mini;
}