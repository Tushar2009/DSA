#include <bits/stdc++.h>
using namespace std;
int f(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = 0;
    int left = 0;
    up = f(i - 1, j, dp);
    left = f(i, j - 1, dp);
    return dp[i][j] = up + left;
}
int main()
{
    int m = 3, n = 3;
    vector<vector<int>> dp(m, vector<int>(n, -1));
    cout << "Total no. of ways :" << f(m - 1, n - 1, dp);
}