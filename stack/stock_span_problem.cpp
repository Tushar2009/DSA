#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void  stock_span(int arr[],int n)
{
    stack<int> st;
    st.push(0);
    cout<<1<<endl;
    int span;
    for(int i=1;i<n;i++)
    {
        while(st.empty()==false && arr[st.top()]<=arr[i])
        {
            st.pop();
        }
        span =st.empty() ? i+1:i-st.top();
        cout<<span<<endl;
        st.push(i);
    }
}
int main()
{
    int arr[]={60,10,20,40,35,30,50,70,65};
    stock_span(arr,9);
    return 0;
}