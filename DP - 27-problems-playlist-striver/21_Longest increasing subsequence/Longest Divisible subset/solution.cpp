#include <bits/stdc++.h>
using namespace std;
vector<int> divisibleSet(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    vector<int> dp(n, 1), hash(n);
    int maxi = 1;
    int lastIndex = 0;
    sort(arr.begin(), arr.end());

    for (int ind = 0; ind < n; ind++)
    {
        hash[ind] = ind;
        for (int prev = 0; prev < ind; prev++)
        {
            if (arr[ind] % arr[prev] == 0 && dp[ind] < 1 + dp[prev])
            {
                dp[ind] = 1 + dp[prev];
                hash[ind] = prev;
            }
        }
        if (dp[ind] > maxi)
        {
            maxi = dp[ind];
            lastIndex = ind;
        }
    }
    vector<int> ans;
    ans.push_back(arr[lastIndex]);
    while (hash[lastIndex] != lastIndex)
    {
        lastIndex = hash[lastIndex];
        ans.push_back(arr[lastIndex]);
    }
    reverse(ans.begin(), ans.end());
    return ans;
}