#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(2^t * k) where t is the target, k is the average length
// Space Complexity: O(k*x)
void printF(int Ind, int target, vector<int> &res, vector<int> &arr, vector<vector<int>> &ans)
{
    if (Ind == arr.size())
    {
        if (target == 0)
        {
            ans.push_back(res);
        }
        return;
    }
    if (arr[Ind] <= target)
    {
        res.push_back(arr[Ind]);
        printF(Ind, target - arr[Ind], res, arr, ans);
        res.pop_back();
    }
    printF(Ind + 1, target, res, arr, ans);
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target)
{
    vector<vector<int>> ans;
    vector<int> ds;
    printF(0, target, ds, candidates, ans);
    return ans;
}