#include <bits/stdc++.h>
using namespace std;
int mod = (int)(1e9 + 7);
int f(int ind, int S, vector<int> &num, vector<vector<int>> &dp)
{
    //     if(S==0)return 1;
    if (ind == 0)
    {
        if (S == 0 && num[0] == 0)
            return 2; // take or n  ot take
        if (S == 0 || S == num[0])
            return 1;
        return 0;
    }
    if (dp[ind][S] != -1)
        return dp[ind][S];
    int not_pick = f(ind - 1, S, num, dp);
    int pick = 0;
    if (num[ind] <= S)
    {
        pick = f(ind - 1, S - num[ind], num, dp);
    }
    return dp[ind][S] = (pick + not_pick) % mod;
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar + 1, -1));
    return f(n - 1, tar, num, dp);
}
int countPartitions(int n, int d, vector<int> &arr)
{
    // Write your code here.
    int total = 0;
    for (int i = 0; i < n; i++)
        total += arr[i];
    if (total - d < 0 || (total - d) % 2)
        return false;
    return (findWays(arr, (total - d) / 2)) % mod;
}