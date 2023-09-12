#include <bits/stdc++.h>
using namespace std;
long countWaysToMakeChange(int *denominations, int n, int value)
{
    // Write your code here
    vector<long> prev(value + 1, 0), cur(value + 1, 0);
    for (int T = 0; T <= value; T++)
    {
        if (T % denominations[0] == 0)
            prev[T] = 1;
        else
            prev[T] = 0;
    }
    for (int ind = 1; ind < n; ind++)
    {
        for (int T = 0; T <= value; T++)
        {
            long not_take = prev[T];
            long take = 0;
            if (denominations[ind] <= T)
            {
                take = cur[T - denominations[ind]];
            }
            cur[T] = not_take + take;
        }
        prev = cur;
    }
    return prev[value];
}