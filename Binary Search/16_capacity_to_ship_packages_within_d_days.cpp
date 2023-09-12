#include <bits/stdc++.h>
using namespace std;
int findMax(vector<int> &weights)
{
    int maxi = INT_MIN;
    for (int i = 0; i < weights.size(); i++)
    {
        maxi = max(maxi, weights[i]);
    }
    return maxi;
}
int sumW(vector<int> &arr)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += arr[i];
    }
    return sum;
}
int possible(vector<int> &weights, int cap)
{
    int days = 1;
    int load = 0;
    for (int i = 0; i < weights.size(); i++)
    {
        if (load + weights[i] > cap)
        {
            days = days + 1;
            load = weights[i];
        }
        else
        {
            load += weights[i];
        }
    }
    return days;
}
int shipWithinDays(vector<int> &arr, int days)
{
    int low = findMax(arr), high = sumW(arr);
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (possible(arr, mid) <= days)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}