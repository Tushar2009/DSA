#include<iostream>
#include<bits/stdc++.h>
using namespace std;
void  prev_greater(int arr[],int n)
{
    stack<int> st;
    st.push(arr[0]);
    cout<<-1<<endl;
    int prev_great;
    for(int i=1;i<n;i++)
    {
        while(st.empty()==false && st.top()<=arr[i])
        {
            st.pop();
        }
        prev_great =st.empty() ? -1:st.top();
        cout<<prev_great<<endl;
        st.push(arr[i]);
    }
}
int main()
{
    int arr[]={20,30,10,5,15};
    prev_greater(arr,5);
    return 0;
}