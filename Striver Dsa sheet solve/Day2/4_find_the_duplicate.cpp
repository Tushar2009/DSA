#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(N), as we are traversing through the array only once.
// Space Complexity: O(N), as we are using extra space for frequency array.
int findDuplicate(vector<int> &nums)
{
    map<int, int> mp;
    for (int i = 0; i < nums.size(); i++)
    {
        if (mp[nums[i]])
        {
            return nums[i];
        }
        mp[nums[i]]++;
    }
    return -1;
}
// Time complexity: O(N). Since we traversed through the array only once.
// Space complexity: O(1).
int findDuplicate(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[0];
    do
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    } while (slow != fast);
    fast = nums[0];
    while (slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;
}