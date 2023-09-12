#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(log(max(arr[]))*N)
int findMax(vector<int> &arr)
{
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}
int possible(vector<int> &arr, int Div)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += ceil((double)(arr[i]) / (double)(Div));
    }
    return sum;
}
int smallestDivisor(vector<int> &arr, int limit)
{
    // Write your code here.
    int low = 1, high = findMax(arr);
    int ans = 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (possible(arr, mid) <= limit)
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