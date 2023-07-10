#include <bits/stdc++.h>
using namespace std;
int countPaths(int n, vector<vector<int>> &roads)
{

    // create an adjcency list {v, time}
    vector<pair<int, int>> adj[n];
    for (auto it : roads)
    {
        adj[it[0]].push_back({it[1], it[2]});
        adj[it[1]].push_back({it[0], it[2]});
    }
    // Using Dijkstra's {time, node}
    priority_queue<pair<long, long>, vector<pair<long, long>>,
                   greater<pair<long, long>>>
        pq;
    pq.push({0, 0});

    vector<long> dist(n, INT_MAX), ways(n, 0);
    dist[0] = 0;
    ways[0] = 1;
    int mod = (int)1e9 + 7;
    while (!pq.empty())
    {
        long dis = pq.top().first;
        int node = pq.top().second;
        pq.pop();

        for (auto it : adj[node])
        {
            int adjNode = it.first;
            long edgeW = it.second;

            if (dis + edgeW < dist[adjNode])
            {
                dist[adjNode] = dis + edgeW;
                pq.push({dist[adjNode], adjNode});
                ways[adjNode] = ways[node] % mod;
            }
            else if (dis + edgeW == dist[adjNode])
            {
                ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
            }
        }
    }

    return ways[n - 1] % mod;
}