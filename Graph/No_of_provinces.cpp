#include <bits/stdc++.h>
using namespace std;
void dfs(int Node, vector<int> adjLs[], int vis[])
{
    vis[Node] = 1;
    // ans.push_back(Node);
    // traverse all its neighbours
    for (auto it : adjLs[Node])
    {
        if (!vis[it])
        {
            dfs(it, adjLs, vis);
        }
    }
}
int numProvinces(vector<vector<int>> adj, int V)
{
    // code here
    vector<int> adjLs[V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (i != j && adj[i][j] == 1)
            {
                adjLs[i].push_back(j);
                adjLs[j].push_back(i);
            }
        }
    }
    int vis[V] = {0};
    int count = 0;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            count++;
            dfs(i, adjLs, vis);
        }
    }
    return count;
}