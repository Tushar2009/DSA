#include <bits/stdc++.h>
using namespace std;
int f(int ind1, int ind2, string &str1, string &str2, vector<vector<int>> &dp)
{
    if (ind1 < 0 || ind2 < 0)
        return 0;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    // match
    if (str1[ind1] == str2[ind2])
        return dp[ind1][ind2] = 1 + f(ind1 - 1, ind2 - 1, str1, str2, dp);
    // not match
    return dp[ind1][ind2] = 0 + max(f(ind1 - 1, ind2, str1, str2, dp), f(ind1, ind2 - 1, str1, str2, dp));
}
int getLengthOfLCS(string &str1, string &str2)
{
    // Write your code here.
    int n = str1.length();
    int m = str2.length();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return f(n - 1, m - 1, str1, str2, dp);
}