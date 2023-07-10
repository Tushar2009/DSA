#include <bits/stdc++.h>
using namespace std;
int maximumSubarray(vector<int> &num, int k)
{
    // Write your code here.
    int n = num.size();
    vector<int> dp(num.size() + 1, 0);
    for (int ind = n - 1; ind >= 0; ind--)
    {
        int len = 0;
        int maxi = INT_MIN;
        int MaxAns = INT_MIN;
        for (int j = ind; j < min(n, ind + k); j++)
        {
            len++;
            maxi = max(maxi, num[j]);
            int sum = len * maxi + dp[j + 1];
            MaxAns = max(MaxAns, sum);
        }
        dp[ind] = MaxAns;
    }
    return dp[0];
}