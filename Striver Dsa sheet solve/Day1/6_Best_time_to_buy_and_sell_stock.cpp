#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(N)
// space complexity: O(1)
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    int profit = 0;
    int mini = prices[0];
    for (int i = 1; i < n; i++)
    {
        int cost = prices[i] - mini;
        profit = max(profit, cost);
        mini = min(mini, prices[i]);
    }
    return profit;
}