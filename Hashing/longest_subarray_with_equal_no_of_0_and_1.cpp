#include<bits/stdc++.h>
using namespace std;
int longestsub(int arr[],int n)
{
    int res=0;
    for(int i=0;i<n;i++)
    {
        int c0=0,c1=0;
        for(int j=i;j<n;j++)
        {
            if(arr[j]==0)
            {
                c0++;
            }
            else
            {
                c1++;
            }
            if(c0==c1)
            {
                res=max(res,c0+c1);
            }
            
        }
    }
    return res;
}



int longestSubarrayWithGivenSum2(int arr[],int n,int sum)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        {
            arr[i]=-1;
        }
    }
    unordered_map<int,int> m;
    int prev_sum=0,res=0;
    for(int i=0;i<n;i++)
    {
        prev_sum+=arr[i];
        //This condition is for subarray with sum starting from 0th index
        if(prev_sum==sum)
        {
            res=i+1;
        }
        //This condition checks whether the same prev_sum is already there ,if it is already present then we will not add the same
        // prev_sum to the the map as we want longest sub array if we update the same prev_sum with some greater index then we will
        // not able to get the longest subarray if at some prev_sum-sum is that prev_sum we have updated again wth new index 
        if(m.find(prev_sum)==m.end())
        {
            m.insert({prev_sum,i});
        }
        if(m.find(prev_sum-sum)!=m.end())
        {
            res=max(res,i-m[prev_sum-sum]);
        }
    }
    return res;
}
int main()
{
    int arr[] = {1, 1, 1, 0, 1, 0, 1, 1, 1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout <<longestSubarrayWithGivenSum2(arr, n,0);
}