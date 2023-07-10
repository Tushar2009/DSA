#include<iostream>
#include<bits/stdc++.h>
using namespace std;
vector<int> prev_smaller(int arr[],int n)
{
    vector<int> vec;
    stack<int> st;
    st.push(0);
    vec.push_back(-1);
    for(int i=1;i<n-1;i++)
    {
        while(st.empty()==false && arr[st.top()]>=arr[i])
        {
            st.pop();
        }
        int prev_smaller = st.empty()? -1:st.top();
        vec.push_back(prev_smaller);
        st.push(i);
    }
    return vec;
}
vector<int> next_smaller(int arr[],int n)
{
    vector<int> vec;
    stack<int> st;
    st.push(n-1);
    vec.push_back(n);
    for(int i=n-2;i>=0;i--)
    {
        while(st.empty()==false && arr[st.top()]>=arr[i])
        {
            st.pop();
        }
        int next_smaller = st.empty()? 7:st.top();
        vec.push_back(next_smaller);
        st.push(i);
    }
    reverse(vec.begin(),vec.end());
    return vec;
}


int getMaxArea(int arr[],int n)
{
    vector<int>  pr_smaller=prev_smaller(arr,n);
      for(int i=0;i<n;i++)
         {
             cout<<pr_smaller[i]<<" ";
         }
         cout<<endl;
    vector<int>  ne_smaller=next_smaller(arr,n);
      for(int i=0;i<n;i++)
         {
             cout<<ne_smaller[i]<<" ";
         }
         cout<<endl;
    int res=0;
    for(int i=0;i<n;i++)
    {
        int curr=arr[i];
        curr+=(i-pr_smaller[i]-1)*arr[i]; // no. of previous smaller elements
        curr+=(ne_smaller[i]-i-1)*arr[i]; // no. of next smaller elements
        cout<<curr<<endl;
        res=max(curr,res);

    }
    return res;

}
int main() 
{ 
    int arr[]={6,2,5,4,5,1,6};
    int n=7;
    cout<<"Maximum Area: "<<getMaxArea(arr,n);
    return 0; 
}