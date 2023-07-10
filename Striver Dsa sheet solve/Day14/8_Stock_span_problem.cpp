#include <bits/stdc++.h>
using namespace std;
// Time Complexity is O(n)
// space complexity is O(n)
class StockSpanner
{
public:
    StockSpanner()
    {
    }
    stack<pair<int, int>> st;
    int i = 0;
    int next(int price)
    {
        if (st.empty())
        {
            st.push({price, i++});
            return 1;
        }
        else
        {
            // previous greater
            while (!st.empty() && st.top().first <= price)
            {
                st.pop();
            }
            int ans = st.empty() ? i + 1 : i - st.top().second;
            st.push({price, i++});
            return ans;
        }
    }
};