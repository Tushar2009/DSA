#include<bits/stdc++.h>
using namespace std;
void func(int ind,int sum,vector<int> &arr,int N,vector<int> &subsetSum)
{
    if(ind==N)
    {
        subsetSum.push_back(sum);
        return;
    }
    //pick
    func(ind+1,sum+arr[ind],arr,N,subsetSum);
    //not pick
    func(ind+1,sum,arr,N,subsetSum);
}
int main()
{
    vector<int> arr;
    arr.push_back(3);
    arr.push_back(1);
    arr.push_back(2);
    vector<int> subsetSum;
    int N=3;
    func(0,0,arr,N,subsetSum);
    sort(subsetSum.begin(),subsetSum.end());
    for(int i=0;i<subsetSum.size();i++)
    {
        cout << subsetSum[i]<<" ";
    }
    return 0;
}