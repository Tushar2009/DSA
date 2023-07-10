#include<bits/stdc++.h>
using namespace std;
stack<int> st;
void insertatbottom(int item)
{
    if(st.size()==0)
    {
        st.push(item);
    }
    else
    {
        int x=st.top();
        st.pop();
        insertatbottom(item);
        st.push(x);
    }
}
void Reverse()
{
    if(st.size()>0)
    {
        int x=st.top();
        st.pop();
        Reverse();
        insertatbottom(x);
    }
}
int main()
{
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    Reverse();

    while(!st.empty())
    {
        int x=st.top();
        cout<<x<<" ";
        st.pop();
    }
    return 0;

}