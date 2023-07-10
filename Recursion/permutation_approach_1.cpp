#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void recurpermutation(vector<int> &ds,vector<int> &nums,vector<vector<int>> &ans,int freq[])
{
    if(ds.size() == nums.size())
    {
        ans.push_back(ds);
        return;
    }
    for(int i=0;i<nums.size();i++)
    {
        if(!freq[i])
        {
             ds.push_back(nums[i]);
             freq[i]=1;
             recurpermutation(ds,nums,ans,freq);
             freq[i]=0;
             ds.pop_back();
        }
    }
}
int main()
{
    vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[nums.size()]={0};
    for(int i=0;i<nums.size();i++)freq[i]=0;
    recurpermutation(ds,nums,ans,freq);
    return 0;
}