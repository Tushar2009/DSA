#include<bits/stdc++.h>
using namespace std;
//Naive way
//Time complexity is O(nlogn)
int longestSub1(int arr[],int n)
{
    sort(arr,arr+n);
    int res=1,curr=1;
    for(int i=1;i<n;i++)
    {
        if(arr[i]==arr[i-1]+1)curr++;
        else if(arr[i]!=arr[i-1])
        {
            res=max(res,curr);
            curr=1;
        }
    }
    return max(res,curr);
}


//Efficient way
//Time complexity is theta(n)
//aux space is O(n)
//logic : Here is if the previous element is not present in set then it is the starting point of subsequence
int longestSub2(int arr[],int n)
{
    unordered_set<int> s(arr,arr+n);
    int res=1;
    for(auto x:s)
    {
        if(s.find(x-1)==s.end())
        {
            int curr=1;
            while(s.find(x+curr)!=s.end())
            {
                curr++;
            }
            res=max(res,curr);
        }
    }
    return res;
}



int main()
{
    int arr[] = {1, 9, 3, 4, 2, 10, 13};
   
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout << longestSub2(arr, n);
}