#include <bits/stdc++.h>
using namespace std;
int getMaxArea(vector<int> &arr, int n)
{
    // Your code here
    stack<int> st;
    int Max_area = 0;
    for (int i = 0; i <= n; i++)
    {
        while (!st.empty() && (i == n || arr[st.top()] > arr[i]))
        {
            int height = arr[st.top()];
            st.pop();
            int width;
            if (st.empty())
                width = i;
            else
                width = i - st.top() - 1;
            Max_area = max(Max_area, height * width);
        }
        st.push(i);
    }
    return Max_area;
}
int maximalAreaOfSubMatrixOfAll1(vector<vector<int>> &mat, int n, int m)
{
    // Write your code here.
    int Max_area = 0;
    vector<int> height(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1)
                height[j]++;
            else
                height[j] = 0;
        }
        Max_area = max(Max_area, getMaxArea(height, height.size()));
    }
    return Max_area;
}