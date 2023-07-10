#include <bits/stdc++.h>
using namespace std;
int f(int ind, vector<int> &a, vector<int> &dp, int n)
{
    for (int i = 1; i < n; i++)
    {
        int take = a[i];
        if (i > 1)
            take += dp[i - 2];
        int not_take = 0 + dp[i - 1];
        dp[i] = max(take, not_take);
    }
    return dp[ind];
}
int main()
{
    vector<int> a;
    a.push_back(2);
    a.push_back(1);
    a.push_back(4);
    a.push_back(9);
    int n = 4;
    vector<int> dp(n, -1);
    dp[0] = a[0];
    cout << f(n - 1, a, dp, n);

    return 0;
}