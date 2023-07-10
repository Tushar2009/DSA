#include <bits/stdc++.h>
using namespace std;
int getLengthOfLCS(string &str1, string &str2)
{
    // Write your code here.
    int n = str1.length();
    int m = str2.length();
    // right shift logic is used to tackle the case of the negative number in tabulation
    //  vector<vector<int>> dp(n+1,vector<int>(m+1,0));
    vector<int> prev(m + 1, 0), cur(m + 1, 0);
    for (int ind2 = 0; ind2 <= m; ind2++)
        prev[ind2] = 0;
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            // match
            if (str1[ind1 - 1] == str2[ind2 - 1])
                cur[ind2] = 1 + prev[ind2 - 1];
            // not match
            else
                cur[ind2] = 0 + max(prev[ind2], cur[ind2 - 1]);
        }
        prev = cur;
    }
    return prev[m];
}