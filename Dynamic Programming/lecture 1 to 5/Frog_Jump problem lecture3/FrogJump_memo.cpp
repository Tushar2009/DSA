#include <bits/stdc++.h>
using namespace std;
int f(int ind, vector<int> &height, vector<int> &dp)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int left = abs(height[ind] - height[ind - 1]) + f(ind - 1, height, dp);
    int right = INT_MAX;
    if (ind > 1)
        right = abs(height[ind] - height[ind - 2]) + f(ind - 2, height, dp);
    return dp[ind] = min(left, right);
}
int main()
{
    vector<int> height;
    height.push_back(10);
    height.push_back(20);
    height.push_back(30);
    height.push_back(10);
    vector<int> dp(height.size() + 1, -1);
    cout << f(height.size() - 1, height, dp);
    return 0;
}