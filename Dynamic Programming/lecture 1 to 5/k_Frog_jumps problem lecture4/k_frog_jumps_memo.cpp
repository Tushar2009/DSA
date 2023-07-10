#include <bits/stdc++.h>
using namespace std;
int f(int ind, vector<int> &height, vector<int> &dp, int k)
{
    if (ind == 0)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int minsteps = INT_MAX;
    // this loop is used for k jumps i+1,i+2,i+3......i+k
    for (int i = 1; i <= k; i++)
    {
        int jump;
        if (ind - i >= 0)
            jump = f(ind - i, height, dp, k) + abs(height[ind] - height[ind - i]);
        minsteps = min(minsteps, jump);
    }
    return dp[ind] = minsteps;
}
int main()
{
    vector<int> height;
    height.push_back(10);
    height.push_back(20);
    height.push_back(30);
    height.push_back(10);
    vector<int> dp(height.size() + 1, -1);
    int k = 3;
    cout << f(height.size() - 1, height, dp, k);
    return 0;
}