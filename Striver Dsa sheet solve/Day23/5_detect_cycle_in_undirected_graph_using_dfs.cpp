#include <bits/stdc++.h>
using namespace std;
bool detect_cycle_DFS(int node, int parent, vector<int> adj[], int vis[])
{
    vis[node] = 1;
    for (auto adjacentNode : adj[node])
    {
        if (!vis[adjacentNode])
        {
            if (detect_cycle_DFS(adjacentNode, node, adj, vis) == true)
                return true;
        }
        else if (adjacentNode != parent)
        {
            return true;
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    // Code here
    int vis[V] = {0};
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (detect_cycle_DFS(i, -1, adj, vis))
                return true;
        }
    }
    return false;
}