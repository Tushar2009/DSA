#include<bits/stdc++.h>
#include<deque>
#include<iostream>
using namespace std;
void printKmax(int arr[],int n,int k)
{
    deque<int> dq;
    //for first k elements
    for(int i=0;i<k;i++)
    {
        while(!dq.empty() && arr[i]>=arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    //for n-k elements
    for(int i=k;i<n;i++)
    {
        cout<<arr[dq.front()]<<" ";
        while(!dq.empty() && dq.back()<=i-k)
        {
            dq.pop_front();
        }
        while(!dq.empty() && arr[i]>=arr[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(i);
    }
    cout<<arr[dq.front()]<<" ";
}
int main()
{
    int arr[]={1,2,3,1,4,5,2,3,6};
    printKmax(arr,9,3);
    return 0;
}