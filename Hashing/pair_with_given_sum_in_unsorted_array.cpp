#include<bits/stdc++.h>
using namespace std;
//efficient way 
//Time complexity is O(n)
//Aux space is O(n)
bool isPairSum(int arr[],int sum,int n)
{
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    {
       if(s.find(sum-arr[i])!=s.end())
       {
          return true;
       }
       else
       {
         s.insert(arr[i]);
       }
    }
    return false;
}
int main()
{
    int arr[]={8,3,4,2,5};
    int sum=6;
    if(isPairSum(arr,sum,5))
    {
        cout<<"pair found"<<endl;
    }
    else
    {
        cout<<"pair not found"<<endl;
    }
}