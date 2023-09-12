#include <bits/stdc++.h>
using namespace std;
// Memoization
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
// Tabulation

#include <bits/stdc++.h>
using namespace std;
int getLengthOfLCS(string &str1, string &str2)
{
    // Write your code here.
    int n = str1.length();
    int m = str2.length();
    // right shift logic is used to tackle the case of the negative number in tabulation
    // 1- Based Indexing
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int ind2 = 0; ind2 <= m; ind2++)
        dp[0][ind2] = 0;
    for (int ind1 = 0; ind1 <= n; ind1++)
        dp[ind1][0] = 0;
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            // match
            if (str1[ind1 - 1] == str2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            // not match
            else
                dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }
    return dp[n][m];
}