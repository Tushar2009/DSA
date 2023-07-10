#include <bits/stdc++.h>
using namespace std;
int celebrity(vector<vector<int>> &M, int n)
{
    // code here
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    while (st.size() >= 2)
    {
        int i = st.top();
        st.pop();
        int j = st.top();
        st.pop();
        if (M[i][j] == 1)
        {
            st.push(j);
        }
        else
        {
            st.push(i);
        }
    }
    int p = st.top();
    st.pop();
    for (int i = 0; i < n; i++)
    {
        if (i != p)
        {
            if (M[i][p] == 0 || M[p][i] == 1)
            {
                return -1;
            }
        }
    }
    return p;
}