#include <bits/stdc++.h>
using namespace std;
void solve(int arr[], int n, int k, int cur_sum, int count, vector<bool> &vis, int sum, bool &ans)
{
    // Write your code here.
    if (count == k)
    {
        ans = true;
        return;
    }
    if (cur_sum > sum)
        return;
    if (cur_sum == sum)
    {
        return solve(arr, n, k, 0, count + 1, vis, sum, ans);
        if (ans == true)
        {
            return;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            vis[i] = true;
            solve(arr, n, k, cur_sum + arr[i], count, vis, sum, ans);
            if (ans == true)
                return;
            vis[i] = false;
        }
    }
}
bool isKPartitionPossible(int a[], int n, int k)
{
    // Your code here
    if (k == 1)
        return true;
    if (k > n)
        return false;
    int total = 0;
    for (int i = 0; i < n; i++)
        total += a[i];
    if (total % k != 0)
        return false;
    vector<bool> vis(n, false);
    bool ans = false;
    solve(a, n, k, 0, 0, vis, total / k, ans);
    return ans;
}