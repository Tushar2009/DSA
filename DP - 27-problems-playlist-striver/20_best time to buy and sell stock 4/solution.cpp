#include <bits/stdc++.h>
using namespace std;
int maximumProfit(vector<int> &prices, int n, int k)
{
    // Write your code here.
    // Write your code here
    vector<vector<int>> ahead(2, vector<int>(k + 1, 0));
    vector<vector<int>> cur(2, vector<int>(k + 1, 0));
    for (int ind = 0; ind <= n; ind++)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            ahead[buy][0] = 0;
        }
    }
    for (int buy = 0; buy <= 1; buy++)
    {
        for (int cap = 0; cap <= k; cap++)
        {
            ahead[buy][cap] = 0;
        }
    }
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= k; cap++)
            {
                int profit = 0;
                if (buy)
                {
                    profit = max(-prices[ind] + ahead[0][cap], 0 + ahead[1][cap]);
                }
                else
                {
                    profit = max(prices[ind] + ahead[1][cap - 1], 0 + ahead[0][cap]);
                }
                cur[buy][cap] = profit;
            }
        }
        ahead = cur;
    }
    return ahead[1][k];
}
