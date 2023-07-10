#include<bits/stdc++.h>
using namespace std;
//naive way
// Time complexity is O(nlogn)
void printNByK(int arr[],int n,int k)
{
    sort(arr,arr+n);
    int i=1,count=1;
    while(i<n)
    {
        while(i<n && arr[i]==arr[i-1])
        {
            count++;
            i++;
        }
        if(count>n/k)
        {
            cout<<arr[i-1]<<" ";

        }
        count=1;
        i++;
    }
}



//efficient way
void printNByK2(int arr[], int n, int k)
{
    unordered_map<int,int> m;
    
    for(int i=0;i<n;i++)
        m[arr[i]]++;
    for(auto e: m)
        if(e.second>n/k)
            cout<<e.first<<" ";
    
}
int main()
{
    int arr[] = {10, 10, 20, 30, 20, 10,10};
   
    int n = sizeof(arr)/sizeof(arr[0]);
    int k=2;
    printNByK2(arr, n, k);
}