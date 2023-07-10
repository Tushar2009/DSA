#include <bits/stdc++.h>
using namespace std;
void insert(stack<int> &s, int temp)
{
    if (s.empty() || s.top() <= temp)
    {
        s.push(temp);
        return;
    }
    else
    {
        int val = s.top();
        s.pop();
        insert(s, temp);
        s.push(val);
        return;
    }
}
void sortStack(stack<int> &st)
{
    // Write your code here
    if (st.size() == 1)
        return;
    int temp = st.top();
    st.pop();
    sortStack(st);
    insert(st, temp);
    return;
}