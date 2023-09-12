#include <bits/stdc++.h>
using namespace std;
int f(int i, int j, string &s, string &t, vector<vector<double>> &dp)
{
    if (j == 0)
        return 1;
    if (i == 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i - 1] == t[j - 1])
    {
        return dp[i][j] = f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp);
    }
    return dp[i][j] = f(i - 1, j, s, t, dp);
}
int numDistinct(string s, string t)
{
    int n = s.size();
    int m = t.size();
    vector<vector<double>> dp(n + 1, vector<double>(m + 1, -1));
    return (int)f(n, m, s, t, dp);
}