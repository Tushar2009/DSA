#include <bits/stdc++.h>
using namespace std;
// Time Complexity: For an undirected graph, O(N) + O(2E), For a directed graph, O(N) + O(E), Because for every node we are calling the recursive function once, the time taken is O(N) and 2E is for total degrees as we traverse for all adjacent nodes.

// Space Complexity: O(3N) ~ O(N), Space for dfs stack space, visited array and an adjacency list.
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