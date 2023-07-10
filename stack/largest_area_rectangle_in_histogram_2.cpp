#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int getMaxArea(int arr[],int n)
{
    stack<int> s;
    int res=0;
    int curr;
    //to find the previous smaller elements then current  element so that its area can be added to current area
    for(int i = 0; i < n; i++)
    {
        while(s.empty()==false && arr[s.top()]>=arr[i])
        {
            int tp=s.top();
            s.pop();
            curr=arr[tp]*(s.empty()? i:i-s.top()-1);
            res=max(res,curr);
        }
        s.push(i);
    }
    //for the elements which do not have previous greater elements then current element
    while(s.empty()==false)
    {
        int tp=s.top();
        s.pop();
        curr=arr[tp]*(s.empty()? n:n-s.top()-1);
        res=max(res,curr);
    }
    return res;
}
int main() 
{ 
    int arr[]={6,2,5,4,1,5,6};
    int n=7;
    cout<<"Maximum Area: "<<getMaxArea(arr,n);
    return 0; 
}