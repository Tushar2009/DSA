#include <bits/stdc++.h>
using namespace std;
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    int n = num.size();
    vector<int> prev(x + 1, 0), curr(x + 1, 0);
    vector<vector<int>> dp(num.size(), vector<int>(x + 1, 0));
    for (int T = 0; T <= x; T++)
    {
        if (T % num[0] == 0)
            prev[T] = T / num[0];
        else
            prev[T] = 1e9;
    }
    for (int i = 1; i < n; i++)
    {
        for (int T = 0; T <= x; T++)
        {
            int not_take = 0 + prev[T];
            int take = 1e9;
            if (num[i] <= T)
            {
                take = 1 + curr[T - num[i]];
            }
            curr[T] = min(take, not_take);
        }
        prev = curr;
    }
    int ans = prev[x];
    if (ans >= 1e9)
        return -1;
    return ans;
}