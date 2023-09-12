#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void recurpermutation(int ind,vector<int> &nums,vector<vector<int>> &ans)
{
    if(ind==nums.size())
    {
        ans.push_back(nums);
        return;
    }
    for(int i=ind;i<nums.size();i++)
    {
        swap(nums[ind],nums[i]);
        recurpermutation(ind+1,nums,ans);
        swap(nums[ind],nums[i]);
    }
}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector<vector<int>> ans;
    recurpermutation(0,nums,ans);
    return 0;
}