#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(int low, int high, string s)
{
    while (low < high)
    {
        if (s[low] != s[high])
            return false;
        low++;
        high--;
    }
    return true;
}
int f(int i, int n, string &str, vector<int> &dp)
{
    if (i == n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int minCost = INT_MAX;
    for (int j = i; j < n; j++)
    {
        if (isPalindrome(i, j, str))
        {
            int cost = 1 + f(j + 1, n, str, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}
int palindromicPartition(string str)
{
    // code here
    int n = str.size();
    vector<int> dp(n, -1);
    return f(0, n, str, dp) - 1;
}