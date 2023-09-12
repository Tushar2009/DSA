#include <bits/stdc++.h>
using namespace std;
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> prev(m, 0);
    for (int j = 0; j < m; j++)
        prev[j] = matrix[0][j];

    for (int i = 1; i < n; i++)
    {
        vector<int> curr(m, 0);
        for (int j = 0; j < m; j++)
        {
            int up = matrix[i][j] + prev[j];
            int ld = matrix[i][j];
            if (j - 1 >= 0)
                ld += prev[j - 1];
            else
                ld += -1e9;
            int rd = matrix[i][j];
            if (j + 1 < m)
                rd += prev[j + 1];
            else
                rd += -1e9;
            curr[j] = max(up, max(ld, rd));
        }
        prev = curr;
    }
    int maxi = -1e9;
    for (int j = 0; j < m; j++)
    {
        maxi = max(maxi, prev[j]);
    }
    return maxi;
}