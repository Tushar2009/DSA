#include <bits/stdc++.h>
using namespace std;
bool check(int start, int V, vector<int> adj[], int color[])
{
    queue<int> q;
    q.push(start);
    color[start] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto adjacentNode : adj[node])
        {
            // if the adjacent node is yet not coloured
            // you will give the opposite color of the node
            if (color[adjacentNode] == -1)
            {
                color[adjacentNode] = !color[node];
                q.push(adjacentNode);
            }
            // Is the adjacent node have the same color
            // someone did color it in some other path
            else if (color[adjacentNode] == color[node])
            {
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(int V, vector<int> adj[])
{
    // Code here
    int color[V];
    for (int i = 0; i < V; i++)
        color[i] = -1;
    for (int i = 0; i < V; i++)
    {
        if (color[i] == -1)
        {
            if (check(i, V, adj, color) == false)
            {
                return false;
            }
        }
    }
    return true;
}