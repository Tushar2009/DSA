#include <bits/stdc++.h>
using namespace std;
int f(int ind, vector<int> &a, vector<int> &dp)
{
    if (ind == 0)
        return a[ind];
    if (ind < 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    // take
    int take = a[ind] + f(ind - 2, a, dp);
    // not take
    int not_take = 0 + f(ind - 1, a, dp);

    return dp[ind] = max(take, not_take);
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
    cout << f(n - 1, a, dp);

    return 0;
}