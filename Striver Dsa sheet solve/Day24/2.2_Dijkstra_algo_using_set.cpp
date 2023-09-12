#include <bits/stdc++.h>
using namespace std;
vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    // Code here
    set<pair<int, int>> st;
    vector<int> dist(V, 1e9);
    st.insert({0, S});
    dist[S] = 0;
    while (!st.empty())
    {
        auto it = *(st.begin());
        int node = it.second;
        int dis = it.first;
        st.erase(it);
        for (auto it : adj[node])
        {
            int adjnode = it[0];
            int edgeweight = it[1];

            if (dis + edgeweight < dist[adjnode])
            {
                if (dist[adjnode] != 1e9)
                    st.erase({dist[adjnode], adjnode});
                dist[adjnode] = dis + edgeweight;
                st.insert({dist[adjnode], adjnode});
            }
        }
    }
    return dist;
}