#include <bits/stdc++.h>
using namespace std;
int CheapestFLight(int n, vector<vector<int>> &flights, int src, int dst, int K)
{
    // Code here
    vector<pair<int, int>> adj[n];
    for (auto it : flights)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }
    //{stops,{node,dist}}
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});
    vector<int> dist(n, 1e9);
    dist[src] = 0;
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int cost = it.second.second;
        if (stops > K)
            continue;
        // Time complexity : E(no. of flights)
        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edW = it.second;
            if (cost + edW < dist[adjNode] && stops <= K)
            {
                dist[adjNode] = cost + edW;
                q.push({stops + 1, {adjNode, cost + edW}});
            }
        }
    }

    if (dist[dst] == 1e9)
        return -1;
    return dist[dst];
}