#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int largest_Histogram(int arr[],int n)
{
    stack<int> s;
    int res=0;
    int curr;
    //to find the previous greater elements then current  element so that its area can be added to current area
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
int largest_rectangle(int mat[4][4])
{
    int res=largest_Histogram(mat[0],4);
    for(int i=1;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(mat[i][j]==1)
            {
                mat[i][j]+=mat[i-1][j];
            }
            res=max(res,largest_Histogram(mat[i],4));
        }
        
    }
    return res;
}
int main()
{
    int mat[4][4]={ {0,1,1,0}, 
                 {1,1,1,1},
                 {1,1,1,1},
                 {1,1,0,0}};
    cout<<"largest rectangle size :"<<largest_rectangle(mat)<<endl;
}