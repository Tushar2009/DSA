#include <bits/stdc++.h>
using namespace std;
int cutRod(vector<int> &price, int n)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int N = 0; N <= n; N++)
    {
        dp[0][N] = N * price[0];
    }
    for (int i = 1; i < n; i++)
    {
        for (int N = 0; N <= n; N++)
        {
            int not_take = 0 + dp[i - 1][N];
            int take = INT_MIN;
            int rodlength = i + 1;
            if (rodlength <= N)
            {
                take = price[i] + dp[i][N - rodlength];
            }
            dp[i][N] = max(not_take, take);
        }
    }
    return dp[n - 1][n];
}