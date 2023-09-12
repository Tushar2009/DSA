#include <bits/stdc++.h>
using namespace std;
int kthElement(vector<int> &nums1, vector<int> &nums2, int n, int m, int k)
{
    // Write your code here
    if (n > m)
        return kthElement(nums2, nums1, m, n, k);
    int low = max(0, k - m), high = min(k, n);
    int left = k;
    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;

        int l1 = (mid1 == 0) ? INT_MIN : nums1[mid1 - 1];
        int l2 = (mid2 == 0) ? INT_MIN : nums2[mid2 - 1];
        int r1 = (mid1 == n) ? INT_MAX : nums1[mid1];
        int r2 = (mid2 == m) ? INT_MAX : nums2[mid2];
        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 > r2)
        {
            high = mid1 - 1;
        }
        else
        {
            low = mid1 + 1;
        }
    }
    return 0;
}