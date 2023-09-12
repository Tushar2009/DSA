#include <bits/stdc++.h>
using namespace std;
long long int MaximumNonAdjacentSum(vector<int> &a)
{
    int n = a.size();
    long long int prev2 = 0;
    long long int prev = a[0];
    for (int i = 1; i < n; i++)
    {
        int take = a[i];
        if (i > 1)
            take += prev2;
        int not_take = 0 + prev;
        int curri = max(take, not_take);
        prev2 = prev;
        prev = curri;
    }
    return prev;
}
long long int houseRobber(vector<int> &valueInHouse)
{
    // Write your code here.
    int n = valueInHouse.size();
    vector<int> temp1, temp2;
    if (n == 1)
        return valueInHouse[0];
    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            temp1.push_back(valueInHouse[i]);
        if (i != n - 1)
            temp2.push_back(valueInHouse[i]);
    }
    long long int ans1 = MaximumNonAdjacentSum(temp1);
    long long int ans2 = MaximumNonAdjacentSum(temp2);
    return max(ans1, ans2);
}