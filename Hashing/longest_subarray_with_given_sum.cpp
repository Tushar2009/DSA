#include<bits/stdc++.h>
using namespace std;
//naive way
//Time complexity is O(n^2)
// Aux space is O(1)
int longestSubarrayWithGivenSum1(int arr[],int n,int sum)
{
    int res=0;
    for(int i = 0; i < n;i++)
    {
        int curr_sum=0;
        for(int j=i;j<n;j++)
        {
            curr_sum+=arr[j];
            if(curr_sum==sum)
            {
                res=max(res,j-i+1);
            }
        }
    }
    return res;
}

//efficient way
int longestSubarrayWithGivenSum2(int arr[],int n,int sum)
{
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
    int arr[]={5,2,3};
    int n=sizeof(arr)/sizeof(arr[0]);
    int sum=5;
    cout<<"Length of longest subarray with given sum :"<<longestSubarrayWithGivenSum2(arr,n,sum);
}