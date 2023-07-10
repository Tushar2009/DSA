#include <bits/stdc++.h>
using namespace std;
bool ispossible(vector<int> &stalls, int n, int k, int dist)
{
    int cnt_cow = 1;
    int lastPlacedCow = stalls[0];
    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - lastPlacedCow >= dist)
        {
            cnt_cow++;
            lastPlacedCow = stalls[i];
        }
    }
    if (cnt_cow >= k)
        return true;
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int low = 1;
    int high = stalls[n - 1] - stalls[0];
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (ispossible(stalls, n, k, mid))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}