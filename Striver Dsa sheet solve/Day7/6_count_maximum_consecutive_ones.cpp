#include <bits/stdc++.h>
using namespace std;
// Time complexity :O(n)
// space complexity :O(1)
int findMaxConsecutiveOnes(vector<int> &nums)
{
    int cnt = 0, maxi = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 1)
        {
            cnt++;
        }
        else
        {
            cnt = 0;
        }
        maxi = max(maxi, cnt);
    }
    return maxi;
}