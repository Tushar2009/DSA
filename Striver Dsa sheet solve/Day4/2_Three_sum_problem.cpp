#include <bits/stdc++.h>
using namespace std;
// optimal approach
//  Time Complexity : O(n^2)
//  Space Complexity : O(3*k)  // k is the no.of triplets.
vector<vector<int>> threeSum(vector<int> &nums)
{
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    for (int i = 0; i < nums.size() - 2; i++)
    {
        if (i == 0 || (i > 0 && nums[i] != nums[i - 1]))
        {
            int left = i + 1, right = nums.size() - 1, sum = -nums[i];
            while (left < right)
            {
                if (nums[left] + nums[right] == sum)
                {
                    vector<int> temp;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[left]);
                    temp.push_back(nums[right]);
                    res.push_back(temp);
                    while (left < right && nums[left] == nums[left + 1])
                        left++;
                    while (left < right && nums[right] == nums[right - 1])
                        right--;
                    left++;
                    right--;
                }
                else if (nums[left] + nums[right] < sum)
                    left++;
                else
                {
                    right--;
                }
            }
        }
    }
    return res;
}