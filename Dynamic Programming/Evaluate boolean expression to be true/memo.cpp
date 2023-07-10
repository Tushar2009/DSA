#include <bits/stdc++.h>
using namespace std;
int mod = 1000000007;
long long f(int i, int j, int isTrue, string &exp, vector<vector<vector<long long>>> &dp)
{
    if (i > j)
        return 0;
    if (i == j)
    {
        if (isTrue)
            return exp[i] == 'T';
        else
            return exp[i] == 'F';
    }
    if (dp[i][j][isTrue] != -1)
        return dp[i][j][isTrue];
    long long ways = 0;
    for (int ind = i + 1; ind <= j - 1; ind++)
    {
        long long LT = f(i, ind - 1, 1, exp, dp);
        long long LF = f(i, ind - 1, 0, exp, dp);
        long long RT = f(ind + 1, j, 1, exp, dp);
        long long RF = f(ind + 1, j, 0, exp, dp);
        if (exp[ind] == '&')
        {
            if (isTrue)
                ways += ((LT * RT) % mod) % mod;
            else
                ways += ((LF * RT) % mod + (LT * RF) % mod + (LF * RF) % mod) % mod;
        }
        else if (exp[ind] == '|')
        {
            if (isTrue)
                ways += ((LT * RT) % mod + (LF * RT) % mod + (LT * RF) % mod) % mod;
            else
                ways += ((LF * RF) % mod) % mod;
        }
        else
        {
            if (isTrue)
                ways += ((LF * RT) % mod + (LT * RF) % mod) % mod;
            else
                ways += ((LT * RT) % mod + (LF * RF) % mod) % mod;
        }
    }
    return dp[i][j][isTrue] = ways;
}
int evaluateExp(string &exp)
{
    // Write your code here.
    int n = exp.size();
    vector<vector<vector<long long>>> dp(n, vector<vector<long long>>(n, vector<long long>(2, -1)));
    return f(0, n - 1, 1, exp, dp);
}