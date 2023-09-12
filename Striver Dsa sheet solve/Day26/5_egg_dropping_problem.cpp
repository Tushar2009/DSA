#include <bits/stdc++.h>
using namespace std;
// Memoization
int solve(int e, int f, vector<vector<int>> &dp)
{
    if (f == 0 || f == 1)
        return f;
    // if no. of eggs=1 then the in worst case the no. of attempts will be till f(no. of floors)
    if (e == 1)
        return f;
    if (dp[e][f] != -1)
        return dp[e][f];
    int mini = INT_MAX;
    // k here is the partition at each floor
    for (int k = 1; k <= f; k++)
    {
        // Here maximum we have taken because we have been asked about the worst case
        int res = 1 + max(solve(e - 1, k - 1, dp), solve(e, f - k, dp));
        mini = min(mini, res); // minimum no. of attempts
    }
    return dp[e][f] = mini;
}
int superEggDrop(int e, int f)
{
    vector<vector<int>> dp(e + 1, vector<int>(f + 1, -1));
    return solve(e, f, dp);
}