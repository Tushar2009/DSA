#include <bits/stdc++.h>
using namespace std;
int f(int ind, vector<int> &height, vector<int> &dp)
{

    for (int i = 1; i < height.size(); i++)
    {

        int left = dp[i - 1] + abs(height[i] - height[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = dp[i - 2] + abs(height[i] - height[i - 2]);
        dp[i] = min(left, right);
    }
    return dp[ind - 1];
}
int main()
{
    vector<int> height;
    height.push_back(10);
    height.push_back(20);
    height.push_back(30);
    height.push_back(10);
    vector<int> dp(height.size(), -1);
    dp[0] = 0;
    cout << f(height.size() - 1, height, dp);
    return 0;
}