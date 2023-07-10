#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// its basically a variation of stock span problem
vector<int>  next_greater(int arr[],int n)
{
    stack<int> st;
    vector<int> vec;
    st.push(arr[n-1]);
    vec.push_back(-1);
    int next_great;
    for(int i=n-2;i>=0;i--)
    {
        while(st.empty()==false && st.top()<=arr[i])
        {
            st.pop();
        }
        next_great =st.empty() ? -1:st.top();
        vec.push_back(next_great);
        st.push(arr[i]);
    }
    reverse(vec.begin(),vec.end());
    return vec;
}
int main()
{
    int arr[]={5,15,10,8,6,12,9,18};
    vector<int> vec;
    vec=next_greater(arr,8);
    for(int i=0;i<vec.size();i++)
    {
        cout<<vec[i]<<" ";
    }
    return 0;
}