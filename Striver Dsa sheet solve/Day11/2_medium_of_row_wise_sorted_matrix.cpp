#include <bits/stdc++.h>
using namespace std;
int countSmallerthanMid(vector<int> &row, int mid)
{
    int l = 0, h = row.size() - 1;
    while (l <= h)
    {
        int md = (l + h) >> 1;
        if (row[md] <= mid)
        {
            l = md + 1;
        }
        else
        {
            h = md - 1;
        }
    }
    return l;
}
int getMedian(vector<vector<int>> &matrix)
{
    // Write your code here.
    int low = 0;
    int high = 1e9;
    int m = matrix.size();    // rows
    int n = matrix[0].size(); // columns
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int cnt = 0;
        for (int i = 0; i < m; i++)
        {
            cnt += countSmallerthanMid(matrix[i], mid);
        }
        if (cnt <= (n * m) / 2)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}