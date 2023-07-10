#include <bits/stdc++.h>
using namespace std;
vector<int> topoSort(int V, vector<int> adj[])
{
    // code here
    int indegree[V] = {0};
    for (int i = 0; i < V; i++)
    {
        for (auto it : adj[i])
        {
            indegree[it]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < V; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> topo;

    // Time complexity: O(v+E)
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        topo.push_back(node);
        // node is in your topo sort
        // so plz remove it from the indegree
        for (auto it : adj[node])
        {
            indegree[it]--;
            if (indegree[it] == 0)
            {
                q.push(it);
            }
        }
    }
    return topo;
}
string findOrder(string dict[], int N, int K)
{
    // code here
    vector<int> adj[K];
    for (int i = 0; i < N - 1; i++)
    {
        string s1 = dict[i];
        string s2 = dict[i + 1];
        int len = min(s1.size(), s2.size());
        for (int ptr = 0; ptr < len; ptr++)
        {
            if (s1[ptr] != s2[ptr])
            {
                // minus 'a' is done so that it will be stored in terms of numbers 0  1  2  3 ....
                adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
                break;
            }
        }
    }
    vector<int> topo = topoSort(K, adj);
    string ans = "";
    for (auto it : topo)
    {
        ans += char(it + 'a');
    }
    return ans;
}