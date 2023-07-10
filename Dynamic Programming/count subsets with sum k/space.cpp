#include <bits/stdc++.h>
using namespace std;
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<int> prev(tar + 1, 0), curr(tar + 1);
    prev[0] = curr[0] = 1;
    if (num[0] <= tar)
        prev[num[0]] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int target = 0; target <= tar; target++)
        {
            int not_pick = prev[target];
            int pick = 0;
            if (num[i] <= target)
            {
                pick = prev[target - num[i]];
            }
            curr[target] = pick + not_pick;
        }
        prev = curr;
    }
    return prev[tar];
}