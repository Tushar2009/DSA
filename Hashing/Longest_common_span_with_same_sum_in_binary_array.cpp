#include<bits/stdc++.h>
using namespace std;
int maxCommon(int arr1[],int arr2[],int n)
{
    int res=0;
    for(int i=0;i<n;i++) {
        int sum1=0,sum2=0;
        for(int j=i;j<n;j++)
        {
            sum1+=arr1[j];
            sum2+=arr2[j];
            if(sum1==sum2)
            {
                res=max(res,j-i+1);
            }
        }
    }
    return res;
}


//efficient way 
int longestCommonSum(int arr1[],int arr2[],int n)
{
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=arr1[i]-arr2[i];
    }
    unordered_map<int,int> m;
    int prev_sum=0,res=0;
    for(int i=0;i<n;i++)
    {
        prev_sum+=arr[i];
        //This condition is for subarray with sum starting from 0th index
        if(prev_sum==0)
        {
            res=i+1;
        }
        if(m.find(prev_sum)==m.end())
        {
            m.insert({prev_sum,i});
        }
        if(m.find(prev_sum-0)!=m.end())
        {
            res=max(res,i-m[prev_sum-0]);
        }
    }
    return res;
}
int main() 
{ 
	int arr1[] = {0, 1, 0, 1, 1, 1, 1}; 
	int arr2[] = {1, 1, 1, 1, 1, 0, 1}; 
	int n = sizeof(arr1)/sizeof(arr1[0]); 
	cout << longestCommonSum(arr1, arr2, n); 
	return 0; 
} 