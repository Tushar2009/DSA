#include <bits/stdc++.h>
using namespace std;
int spanningTree(int V, vector<vector<int>> adj[])
{
    // code here
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> vis(V, 0);
    //{weight,node}
    pq.push({0, 0});
    int sum = 0;
    // Time complexity :O(E log E)
    while (!pq.empty())
    {

        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int wt = it.first;
        if (vis[node] == 1)
            continue;
        // add it to the mst
        vis[node] = 1;
        sum += wt;
        for (auto it : adj[node])
        {
            int adjnode = it[0];
            int edW = it[1];
            if (!vis[adjnode])
            {
                pq.push({edW, adjnode});
            }
        }
    }
    return sum;
}