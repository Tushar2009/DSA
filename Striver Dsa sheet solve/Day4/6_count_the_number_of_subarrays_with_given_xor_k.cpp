#include <bits/stdc++.h>
using namespace std;
int subarraysWithSumK(vector<int> a, int b)
{
    // Write your code here
    int xr = 0;
    unordered_map<int, int> mpp;
    mpp[xr] = 1; //{0,1}
    int cnt = 0;
    for (int i = 0; i < a.size(); i++)
    {
        xr = xr ^ a[i];
        int x = xr ^ b;
        cnt += mpp[x];
        mpp[xr]++;
    }
    return cnt;
}