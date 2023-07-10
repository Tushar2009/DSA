#include <bits/stdc++.h>
using namespace std;
bool isPalindome(int i, int j, string str)
{
    while (i < j)
    {
        if (str[i] != str[j])
            return false;
        i++;
        j--;
    }
    return true;
}
int palindromePartitioning(string str)
{
    // Write your code here
    int n = str.size();
    vector<int> dp(n + 1, 0);
    dp[n] = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        int MinCost = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (isPalindome(i, j, str))
            {
                int cost = 1 + dp[j + 1];
                MinCost = min(MinCost, cost);
            }
        }
        dp[i] = MinCost;
    }
    return dp[0] - 1;
}