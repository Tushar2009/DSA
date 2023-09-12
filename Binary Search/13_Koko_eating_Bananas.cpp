#include <bits/stdc++.h>
using namespace std;
int findMax(vector<int> &arr)
{
    int maxi = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}
int calculateTotalHours(vector<int> &v, int hourly)
{
    int totalHours = 0;
    for (int i = 0; i < v.size(); i++)
    {
        totalHours += ceil(double(v[i]) / (double(hourly)));
    }
    return totalHours;
}
int minimumRateToEatBananas(vector<int> v, int h)
{
    // Write Your Code Here
    int low = 1, high = findMax(v);
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int totalH = calculateTotalHours(v, mid);
        if (totalH <= h)
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