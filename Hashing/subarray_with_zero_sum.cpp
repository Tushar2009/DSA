#include<bits/stdc++.h>
using namespace std;
//efficient way
// using prefix sum and hashing
//Time complexity is O(n)
// aux space is O(n)
bool ZeroSumSubarray(int arr[],int n)
{
    int pre_sum=0;
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    {
        pre_sum+=arr[i];
        if(s.find(pre_sum) != s.end())
        {
            return true;
        }
        if(pre_sum==0)
        {
            return true;
        }
        s.insert(pre_sum);
    }
    return false;
}
int main()
{
    int arr[] = {5, 3, 9, -4, -6, 7, -1};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << ZeroSumSubarray(arr, n);
}