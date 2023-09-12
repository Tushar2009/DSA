#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(N) + O(2E), Where N = Nodes, 2E is for total degrees as we traverse all adjacent nodes.

// Space Complexity: O(3N) ~ O(N), Space for queue data structure visited array and an adjacency list
vector<int> bfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    vector<int> bfs;
    int vis[V] = {0};
    vis[0] = 1;
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        bfs.push_back(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                q.push(it);
            }
        }
    }
    return bfs;
}