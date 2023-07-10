#include<bits/stdc++.h>
using namespace std;
void func(int ind,vector<int> &ds,vector<vector<int>> &ans,vector<int> &arr)
{
    ans.push_back(ds);
    for(int i=ind;i<arr.size();i++)
    {
        if(i!=ind && arr[i]==arr[i-1])continue;
        ds.push_back(arr[i]);
        func(ind+1,ds,ans,arr);
        ds.pop_back();
    }
}
int main()
{
    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(3);
    vector<int> ds;
    vector<vector<int>> ans;
    func(0,ds,ans,arr);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
           cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}