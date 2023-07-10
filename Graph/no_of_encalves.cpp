#include <bits/stdc++.h>
using namespace std;
// method 1 BFS
int numberOfEnclaves(vector<vector<int>> &grid)
{
    // Code here
    queue<pair<int, int>> q;
    int n = grid.size();
    int m = grid[0].size();
    int visited[n][m] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (i == 0 || i == n - 1 || j == 0 || j == m - 1)
            {
                if (grid[i][j] == 1)
                {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }
    }
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};
    while (!q.empty())
    {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !visited[nrow][ncol] && grid[nrow][ncol] == 1)
            {
                q.push({nrow, ncol});
                visited[nrow][ncol] = 1;
            }
        }
    }
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!visited[i][j] && grid[i][j] == 1)
            {
                count++;
            }
        }
    }
    return count;
}

// method 2
// DFS
void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, int delrow[], int delcol[])
{
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && grid[nrow][ncol] == 1)
        {
            dfs(nrow, ncol, vis, grid, delrow, delcol);
        }
    }
}
int numberOfEnclaves(vector<vector<int>> &grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, +1, 0, -1};
    int count = 0;
    for (int j = 0; j < m; j++)
    {
        if (!vis[0][j] && grid[0][j] == 1)
        {
            dfs(0, j, vis, grid, delrow, delcol);
        }
        if (!vis[n - 1][j] && grid[n - 1][j] == 1)
        {
            dfs(n - 1, j, vis, grid, delrow, delcol);
        }
    }
    for (int i = 0; i < n; i++)
    {
        // first column
        if (!vis[i][0] && grid[i][0] == 1)
        {
            dfs(i, 0, vis, grid, delrow, delcol);
        }
        // last column
        if (!vis[i][m - 1] && grid[i][m - 1] == 1)
        {
            dfs(i, m - 1, vis, grid, delrow, delcol);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!vis[i][j] && grid[i][j] == 1)
            {
                count++;
            }
        }
    }
    return count;
}