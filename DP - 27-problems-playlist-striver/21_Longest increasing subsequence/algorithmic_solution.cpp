#include <bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> dp(n, 1);
    int maxi = 1;
    for (int ind = 0; ind < n; ind++)
    {
        for (int prev = 0; prev < ind; prev++)
        {
            if (arr[prev] < arr[ind])
            {
                dp[ind] = max(dp[ind], 1 + dp[prev]);
            }
        }
        maxi = max(maxi, dp[ind]);
    }
    return maxi;
}