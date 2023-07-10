#include <bits/stdc++.h>
using namespace std;
int maximumProfit(vector<int> &prices)
{
    // Write your code here.
    int n = prices.size();
    int mini = prices[0], profit = 0;
    for (int i = 1; i < n; i++)
    {
        int cost = prices[i] - mini;
        profit = max(profit, cost);
        // As we know DP means remembering the past
        mini = min(mini, prices[i]);
    }
    return profit;
}