#include <bits/stdc++.h>
using namespace std;
int prefixStrings(int N)
{
    // Your code goes here
    vector<long long> dp(N + 1, 0);
    int mod = 1000000007;
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= N; i++)
    {
        for (int j = 0; j < i; j++)
        {
            dp[i] += ((dp[j] % mod) * (dp[i - j - 1] % mod)) % mod;
        }
    }
    return dp[N] % mod;
}