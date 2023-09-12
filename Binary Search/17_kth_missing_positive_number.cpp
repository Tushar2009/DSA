#include <bits/stdc++.h>
using namespace std;
int findKthPositive(vector<int> &arr, int k)
{
    int low = 0, high = arr.size() - 1;
    // at a particular index the previous missing numbers are arr[i]-(i+1)
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing < k)
            low = mid + 1;
        else
        {
            high = mid - 1;
        }
    }
    // ans=arr[high]+more where more is k-missing and
    // missing is arr[high]-(high+1)
    return (high + 1 + k);
}