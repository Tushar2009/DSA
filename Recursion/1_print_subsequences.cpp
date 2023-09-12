#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void printF(int Index,vector<int> &res,int arr[],int n)
{
    if(Index==n)
    {
        for(auto it:res)
        {
            cout<<it<<" ";
        }
        if(res.size()==0)
        {
            cout<<"{}"<<" ";
        }
        cout<<endl;
       return;
    }
    //take or pick the particular index into the subsequence
    res.push_back(arr[Index]);
   printF(Index+1,res,arr,n);

   //not pick or,Not take condition,this element is not added to your subsequence
   res.pop_back();
   printF(Index+1,res,arr,n);
}

int main()
{
    int arr[]={3,1,2};
    int n=3;
    vector<int> res;
    printF(0,res,arr,n);
}

