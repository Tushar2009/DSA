#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &prices, int n)
{
    // Write your code here
    vector<vector<int>> ahead(2, vector<int>(3, 0));
    vector<vector<int>> cur(2, vector<int>(3, 0));
    for (int ind = 0; ind <= n; ind++)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            ahead[buy][0] = 0;
        }
    }
    for (int buy = 0; buy <= 1; buy++)
    {
        for (int cap = 0; cap <= 2; cap++)
        {
            ahead[buy][cap] = 0;
        }
    }
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int buy = 0; buy <= 1; buy++)
        {
            for (int cap = 1; cap <= 2; cap++)
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
    return ahead[1][2];
}