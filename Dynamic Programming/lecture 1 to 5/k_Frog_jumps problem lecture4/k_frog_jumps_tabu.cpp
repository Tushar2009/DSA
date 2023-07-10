#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> height;
    height.push_back(10);
    height.push_back(20);
    height.push_back(30);
    height.push_back(10);
    vector<int> dp(height.size(), -1);
    dp[0] = 0;
    int k = 3;
    for (int i = 1; i < height.size(); i++)
    {

        for (int j = 1; j <= k; j++)
        {
            int minsteps = INT_MAX;
            int jump;
            if (i - j >= 0)
            {
                jump = dp[i - j] + abs(height[i] - height[i - j]);
                minsteps = min(minsteps, jump);
            }
            dp[i] = minsteps;
        }
    }
    cout << dp[height.size() - 1];
    return 0;
}