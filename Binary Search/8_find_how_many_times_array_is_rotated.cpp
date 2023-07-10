#include <bits/stdc++.h>
using namespace std;
int findKRotation(vector<int> &arr)
{
    // Write your code here.
    int n = arr.size();
    int low = 0, high = n - 1;
    int ans = INT_MAX;
    int index = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[low] <= arr[high])
        {
            if (ans >= arr[low])
            {
                ans = arr[low];
                index = low;
            }
            break;
        }
        if (arr[low] <= arr[mid])
        {
            if (ans >= arr[low])
            {
                ans = arr[low];
                index = low;
            }
            low = mid + 1;
        }
        else
        {
            if (ans >= arr[mid])
            {
                ans = arr[mid];
                index = mid;
            }
            high = mid - 1;
        }
    }
    return index;
}