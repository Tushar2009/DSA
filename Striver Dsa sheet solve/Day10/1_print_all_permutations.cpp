#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(N! X N)
// Space Complexity:  O(N)
void recurpermute(vector<int> &ds, vector<int> &nums, vector<vector<int>> &ans, int freq[])
{
    if (ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (freq[i] == 0)
        {
            ds.push_back(nums[i]);
            freq[i] = 1;
            recurpermute(ds, nums, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
    }
}
vector<vector<int>> permute(vector<int> &nums)
{
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[nums.size()];
    for (int i = 0; i < nums.size(); i++)
        freq[i] = 0;
    recurpermute(ds, nums, ans, freq);
    return ans;
}

// Time Complexity: O(N! X N)
// Space Complexity: O(1)
//  Backtracking solution
class Solution
{
private:
    void recurPermute(int index, vector<int> &nums, vector<vector<int>> &ans)
    {
        if (index == nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for (int i = index; i < nums.size(); i++)
        {
            swap(nums[index], nums[i]);
            recurPermute(index + 1, nums, ans);
            swap(nums[index], nums[i]);
        }
    }

public:
    vector<vector<int>> permute(vector<int> &nums)
    {
        vector<vector<int>> ans;
        recurPermute(0, nums, ans);
        return ans;
    }
};

int main()
{
    Solution obj;
    vector<int> v{1, 2, 3};
    vector<vector<int>> sum = obj.permute(v);
    cout << "All Permutations are" << endl;
    for (int i = 0; i < sum.size(); i++)
    {
        for (int j = 0; j < sum[i].size(); j++)
            cout << sum[i][j] << " ";
        cout << endl;
    }
}