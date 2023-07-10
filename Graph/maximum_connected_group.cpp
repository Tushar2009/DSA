#include <bits/stdc++.h>
using namespace std;
class disjointSet
{

public:
    vector<int> rank, parent, size;
    disjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }
    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }
    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution
{
    bool isValid(int adjr, int adjc, int n)
    {
        if (adjr >= 0 && adjr < n && adjc >= 0 && adjc < n)
        {
            return true;
        }
        return false;
    }

public:
    int MaxConnection(vector<vector<int>> &grid)
    {
        // code here
        int n = grid.size();
        disjointSet ds(n * n);
        // step 1 connecting components
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 0)
                    continue;
                int delrow[] = {-1, 0, +1, 0};
                int delcol[] = {0, +1, 0, -1};
                for (int i = 0; i < 4; i++)
                {
                    int newr = row + delrow[i];
                    int newc = col + delcol[i];
                    if (isValid(newr, newc, n) && grid[newr][newc])
                    {
                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        // step 2 converting 0 to 1
        int maxi = INT_MIN;
        for (int row = 0; row < n; row++)
        {
            for (int col = 0; col < n; col++)
            {
                if (grid[row][col] == 1)
                    continue;
                int delrow[] = {-1, 0, +1, 0};
                int delcol[] = {0, +1, 0, -1};
                set<int> components;
                for (int i = 0; i < 4; i++)
                {
                    int newr = row + delrow[i];
                    int newc = col + delcol[i];
                    if (isValid(newr, newc, n))
                    {
                        if (grid[newr][newc] == 1)
                        {
                            components.insert(ds.findUPar(newr * n + newc));
                        }
                    }
                }
                int sizeTotal = 0;
                for (auto it : components)
                {
                    sizeTotal += ds.size[it];
                }
                maxi = max(maxi, sizeTotal + 1);
            }
        }
        for (int cell = 0; cell < n * n; cell++)
        {
            maxi = max(maxi, ds.size[ds.findUPar(cell)]);
        }
        return maxi;
    }
};