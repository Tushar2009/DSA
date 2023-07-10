#include <bits/stdc++.h>
using namespace std;
// optimal solution
// Time complexity :O(n)

int removeDuplicates(vector<int> &nums)
{
    int i = 0;
    for (int j = i + 1; j < nums.size(); j++)
    {
        if (nums[i] != nums[j])
        {
            i++;
            nums[i] = nums[j];
        }
    }
    return i + 1;
}