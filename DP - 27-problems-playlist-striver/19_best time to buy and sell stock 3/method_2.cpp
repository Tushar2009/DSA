// Memoization
//  #include <bits/stdc++.h>
//  using namespace std;
//  int f(int ind, int transaction, vector<int> &prices, vector<vector<int>> &dp)
//  {
//      if (ind == prices.size() || transaction == 4)
//          return 0;
//      if (dp[ind][transaction] != -1)
//          return dp[ind][transaction];
//      int profit = 0;
//      if (transaction % 2 == 0)
//      {
//          profit = max(-prices[ind] + f(ind + 1, transaction + 1, prices, dp), 0 + f(ind + 1, transaction, prices, dp));
//      }
//      else
//      {
//          profit = max(prices[ind] + f(ind + 1, transaction + 1, prices, dp), 0 + f(ind + 1, transaction, prices, dp));
//      }
//      return dp[ind][transaction] = profit;
//  }
//  int maxProfit(vector<int> &prices, int n)
//  {
//      // Write your code here
//      vector<vector<int>> dp(n, vector<int>(4, -1));
//      return f(0, 0, prices, dp);
//  }

// Tabulation
#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &prices, int n)
{
    // Write your code here
    vector<vector<int>> dp(n + 1, vector<int>(4, 0));
    // for index==n transaction can be any thing
    for (int i = 0; i < 4; i++)
    {
        dp[n][i] = 0;
    }
    for (int i = 0; i <= n; i++)
    {
        dp[i][4] = 0;
    }
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int transaction = 3; transaction >= 0; transaction--)
        {
            int profit = 0;
            if (transaction % 2 == 0)
            {
                profit = max(-prices[ind] + dp[ind + 1][transaction + 1], 0 + dp[ind + 1][transaction]);
            }
            else
            {
                profit = max(prices[ind] + dp[ind + 1][transaction + 1], 0 + dp[ind + 1][transaction]);
            }
            dp[ind][transaction] = profit;
        }
    }

    return dp[0][0];
}

// space optimization
#include <bits/stdc++.h>
using namespace std;
int maxProfit(vector<int> &prices, int n)
{
    // Write your code here
    vector<int> ahead(4, 0);
    vector<int> cur(4, 0);
    // for index==n transaction can be any thing
    for (int i = 0; i < 4; i++)
    {
        ahead[i] = 0;
    }
    ahead[4] = 0;
    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int transaction = 3; transaction >= 0; transaction--)
        {
            int profit = 0;
            if (transaction % 2 == 0)
            {
                profit = max(-prices[ind] + ahead[transaction + 1], 0 + ahead[transaction]);
            }
            else
            {
                profit = max(prices[ind] + ahead[transaction + 1], 0 + ahead[transaction]);
            }
            cur[transaction] = profit;
        }
        ahead = cur;
    }

    return ahead[0];
}
