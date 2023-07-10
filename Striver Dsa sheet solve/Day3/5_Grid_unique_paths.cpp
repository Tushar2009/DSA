#include <bits/stdc++.h>
using namespace std;
// Combinatorics Solution
// Time complexity is O(row-1)
int uniquePaths(int row, int col)
{
    double res = 1;
    int N = (row - 1) + (col - 1); // number of operations I have to perform i.e right and down here (Row-1) denote the right operation and (Col-1) denote the down operation
    int r = row - 1;
    // calculate the nCr to check the no. of combinations of the unique paths
    for (int i = 1; i <= r; i++)
    {
        res = res * (N - r + 1) / i;
    }
    return (int)res;
}

// DP solution(dp on grids)
// Time Complexity: The time complexity of this solution will be O(n*m) because at max there can be n*m number of states.
// Space Complexity: As we are using extra space for the dummy matrix the space complexity will also be O(n*m).
int countPaths(int i, int j, int n, int m, vector<vector<int>> &dp)
{
    if (i == (n - 1) && j == (m - 1))
        return 1;
    if (i >= n || j >= m)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    else
        return dp[i][j] = countPaths(i + 1, j, n, m, dp) + countPaths(i, j + 1, n, m, dp);
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));

    // dp[1][1]=1;
    int num = countPaths(0, 0, m, n, dp);
    if (m == 1 && n == 1)
        return num;
    return dp[0][0];
}