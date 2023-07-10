#include <bits/stdc++.h>
using namespace std;
int findNumberOfLIS(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    vector<int> dp(n, 1), count(n, 1);
    int maxi = 1;
    for (int i = 0; i < n; i++)
    {
        for (int prev = 0; prev < i; prev++)
        {
            if (arr[i] > arr[prev] && dp[i] < dp[prev] + 1)
            {
                dp[i] = 1 + dp[prev];
                count[i] = count[prev];
            }
            else if (arr[i] > arr[prev] && dp[i] == dp[prev] + 1)
            {
                count[i] += count[prev];
            }
        }
        maxi = max(maxi, dp[i]);
    }
    int nos = 0;
    for (int i = 0; i < n; i++)
    {
        if (dp[i] == maxi)
            nos += count[i];
    }
    return nos;
}