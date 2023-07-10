#include <bits/stdc++.h>
using namespace std;
void dfs(int Node, vector<int> adj[], int vis[], vector<int> &ans)
{
    vis[Node] = 1;
    ans.push_back(Node);
    // traverse all its neighbours
    for (auto it : adj[Node])
    {
        if (!vis[it])
        {
            dfs(it, adj, vis, ans);
        }
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{
    // Code here
    int vis[V] = {0};
    int start = 0;
    vector<int> ans;
    dfs(start, adj, vis, ans);
    return ans;
}