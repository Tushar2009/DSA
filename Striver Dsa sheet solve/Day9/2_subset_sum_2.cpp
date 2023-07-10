#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(2^n) for generating every subset and O(k)  to insert every subset in another data structure
// if the average length of every subset is k. Overall O(k * 2^n)
// Space Complexity: O(2^n * k)
// to store every subset of average length k. Auxiliary space is O(n)  if n is the depth of the recursion tree.
void f(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);
    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind && nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        f(i + 1, nums, ds, ans);
        ds.pop_back();
    }
}
vector<vector<int>> subsetsWithDup(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    sort(nums.begin(), nums.end());
    f(0, nums, ds, ans);
    return ans;
}