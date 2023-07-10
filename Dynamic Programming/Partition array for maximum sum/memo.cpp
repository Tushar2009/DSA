#include <bits/stdc++.h>
using namespace std;
int f(int ind, int k, vector<int> &num, int n, vector<int> &dp)
{
    if (ind == n)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int len = 0;
    int maxi = INT_MIN;
    int MaxAns = INT_MIN;
    for (int j = ind; j < min(n, ind + k); j++)
    {
        len++;
        maxi = max(maxi, num[j]);
        int sum = len * maxi + f(j + 1, k, num, n, dp);
        MaxAns = max(MaxAns, sum);
    }
    return dp[ind] = MaxAns;
}
int maximumSubarray(vector<int> &num, int k)
{
    // Write your code here.
    vector<int> dp(num.size(), -1);
    return f(0, k, num, num.size(), dp);
}