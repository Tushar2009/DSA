#include <bits/stdc++.h>
using namespace std;
/**BRUTE force**/
// Time Complexity: O((N*M)*(N + M)) + O(N*M)
// space complexity :O(1)
void helper(int row, int col, vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    // for row marking
    for (int j = 0; j < n; j++)
    {
        if (mat[row][j] != 0)
            mat[row][j] = -1;
    }
    for (int i = 0; i < m; i++)
    {
        if (mat[i][col] != 0)
            mat[i][col] = -1;
    }
}
void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                helper(i, j, matrix);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == -1)
                matrix[i][j] = 0;
        }
    }
}

// Better approach
// Time Complexity: O(2*(N*M))
// Space Complexity: O(N) + O(M), where N = no. of rows in the matrix and M = no. of columns in the matrix.
void setZeroes(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> row(n, 0);
    vector<int> col(m, 0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (row[i] || col[j])
            {
                matrix[i][j] = 0;
            }
        }
    }
}