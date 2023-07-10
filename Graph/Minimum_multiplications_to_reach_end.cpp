#include <bits/stdc++.h>
using namespace std;
int minimumMultiplications(vector<int> &arr, int start, int end)
{
    // code here
    queue<pair<int, int>> q;
    q.push({start, 0});
    vector<int> dist(100000, 1e9);
    dist[start] = 0;
    // time complexity is way lesser than O(100000*N)
    while (!q.empty())
    {
        int node = q.front().first;
        int steps = q.front().second;
        q.pop();
        for (auto it : arr)
        {
            int num = (it * node) % 100000;
            if (steps + 1 < dist[num])
            {
                dist[num] = steps + 1;
                if (num == end)
                    return steps + 1;
                q.push({num, steps + 1});
            }
        }
    }
    return -1;
}