#include <bits/stdc++.h>
using namespace std;
int maximumProduct(vector<int> &arr, int n)
{
    // Write your code here
    int ans = arr[0];
    int ma = ans;
    int mi = ans;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < 0)
        {
            swap(mi, ma);
        }
        ma = max(arr[i], arr[i] * ma);
        mi = min(arr[i], arr[i] * mi);
        ans = max(ans, ma);
    }
    return ans;
}