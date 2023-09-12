#include<bits/stdc++.h>
using namespace std;
void printF(int Index,int target,vector<int> &res,int arr[],int n,vector<vector<int>> &ans)
{
        if(target==0)
        {
            ans.push_back(res);
            return;
        }
    for(int i=Index;i<n;i++)
    {
        if(i>Index && arr[i]==arr[i-1])continue;
        if(arr[i]>target)break;
        res.push_back(arr[i]);
        printF(i+1,target-arr[i],res,arr,n,ans);
        res.pop_back();
    }
}
int main()
{
    int arr[]={1,1,1,2,2};
    int n=5;
    int target=4;
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