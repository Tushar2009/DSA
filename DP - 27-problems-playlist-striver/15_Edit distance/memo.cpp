#include <bits/stdc++.h>
using namespace std;
int f(int i, int j, string &s1, string &s2, vector<vector<int>> &dp)
{
    if (i == 0)
        return j;
    if (j == 0)
        return i;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s1[i - 1] == s2[j - 1])
        return dp[i][j] = 0 + f(i - 1, j - 1, s1, s2, dp);
    return dp[i][j] = 1 + min(f(i, j - 1, s1, s2, dp), min(f(i - 1, j, s1, s2, dp), f(i - 1, j - 1, s1, s2, dp)));
}
int editDistance(string str1, string str2)
{
    // write you code here
    int n = str1.size();
    int m = str2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return f(n, m, str1, str2, dp);
}