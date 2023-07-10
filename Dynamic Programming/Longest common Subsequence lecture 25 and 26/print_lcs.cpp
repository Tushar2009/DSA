#include <bits/stdc++.h>
using namespace std;
void printLCS(string &str1, string &str2)
{
    // Write your code here.
    int n = str1.length();
    int m = str2.length();
    // right shift logic is used to tackle the case of the negative number in tabulation
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
    int len = dp[n][m];
    string str = "";
    for (int i = 0; i < len; i++)
        str += '$';
    int index = len - 1;
    int i = n, j = m;
    while (i > 0 && j > 0)
    {
        if (str1[i - 1] == str2[j - 1])
        {
            str[index] = str1[i - 1];
            index--;
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            i--;
        }
        else
        {
            j--;
        }
    }
    cout << str;
}
int main()
{
    string str1 = "abcde", str2 = "bdgek";
    printLCS(str1, str2);
    return 0;
}