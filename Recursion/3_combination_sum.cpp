#include<bits/stdc++.h>
using namespace std;
void printF(int Index,int target,vector<int> &res,int arr[],int n,vector<vector<int>> &ans)
{
    if(Index==n)
    {
        if(target==0)
        {
            ans.push_back(res);
            return;
        }
    }
    //pick case
    if(arr[Index]<=target)
    {
        res.push_back(arr[Index]);
        printF(Index,target-arr[Index],res,arr,n,ans);
        res.pop_back();
    }
    //not pick case
    printF(Index+1,target,res,arr,n,ans);

}
int main()
{
    int arr[]={2,3,6,7};
    int n=4;
    int target=7;
    vector<int> res;
    vector<vector<int>> ans;
    printF(0,target,res,arr,n,ans);
     for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }    
        cout << endl;
    }
    return 0;
}