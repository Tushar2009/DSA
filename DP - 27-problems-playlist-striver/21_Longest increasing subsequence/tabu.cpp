#include <bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    // vector<int> next(n+1,0),cur(n+1,0);
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev = ind - 1; prev >= -1; prev--)
        {
            // not-take case
            int len = 0 + dp[ind + 1][prev + 1];

            // take case
            if (prev == -1 || arr[ind] > arr[prev])
            {
                len = max(len, 1 + dp[ind + 1][ind + 1]);
            }
            dp[ind][prev + 1] = len;
        }
    }

    return dp[0][-1 + 1];
}