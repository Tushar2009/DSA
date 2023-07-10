#include<bits/stdc++.h>
using namespace std;
//naive way
//Time complexity is O(n^2)
// Aux space is O(1)
bool isSum(int arr[],int n,int sum)
{
    for(int i = 0; i < n;i++)
    {
        int curr_sum=0;
        for(int j=i;j<n;j++)
        {
            curr_sum+=arr[j];
            if(curr_sum==sum)
            {
                return true;
            }
        }
    }
    return false;
}


//Efficient method
// Time complexity is O(n)
// Aux space is O(n)
bool sub_array_sum(int arr[],int n,int sum)
{
    unordered_set<int> s;
    int pre_sum=0;
    for(int i = 0; i < n; i++)
    {
        pre_sum+=arr[i];
        if(pre_sum==sum)return true;
        if(s.find(pre_sum-sum)!=s.end())
        {
            return true;
        }
        s.insert(pre_sum);
    }
    return false;
}
int main()
{
    int arr[] = {5, 8, 6, 13, 3, -1};
    int sum=22;
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << sub_array_sum(arr, n, sum);
}
