#include <bits/stdc++.h>
using namespace std;
string longestPalindrome(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    string ans = "";
    int maxi = 0;
    for (int diff = 0; diff < n; diff++)
    {
        for (int i = 0, j = i + diff; j < n; i++, j++)
        {
            if (i == j)
                dp[i][j] = 1;
            else if (diff == 1)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = 2;
                }
            }
            else
            {
                // to check whether in between characters form the palindrome already
                if (s[i] == s[j] && dp[i + 1][j - 1])
                {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }
            }
            if (dp[i][j])
            {
                if (j - i + 1 > maxi)
                {
                    maxi = j - i + 1;
                    ans = s.substr(i, j - i + 1);
                }
            }
        }
    }
    return ans;
}