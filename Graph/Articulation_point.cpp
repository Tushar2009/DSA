#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    void dfs(int node, int parent, vector<int> &vis, int timer, int tin[], int low[], vector<int> &marks, vector<int> adj[])
    {
        vis[node] = 1;
        low[node] = tin[node] = timer;
        timer++;
        int child = 0;
        for (auto it : adj[node])
        {
            if (it == parent)
                continue;
            if (!vis[it])
            {
                dfs(it, node, vis, timer, tin, low, marks, adj);
                low[node] = min(low[node], low[it]);
                if (low[it] >= tin[node] && parent != -1)
                {
                    marks[node] = 1;
                }
                child++;
            }
            else
            {
                low[node] = min(low[node], tin[it]);
            }
        }
        if (child > 1 && parent == -1)
        {
            marks[node] = 1;
        }
    }
    vector<int> articulationPoints(int n, vector<int> adj[])
    {
        // Code here
        vector<int> vis(n, 0);
        int tin[n];
        int low[n];
        vector<int> marks(n, 0);
        int timer = 0;
        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
            {
                dfs(0, -1, vis, timer, tin, low, marks, adj);
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (marks[i] == 1)
            {
                ans.push_back(i);
            }
        }
        if (ans.size() == 0)
            return {-1};
        return ans;
    }
};