#include <bits/stdc++.h>
using namespace std;
// optimal solution 1
// Time Complexity: O(min(n, m)) + O(n*logn) + O(m*logm)
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{
    // Write your code here.
    int left = a.size() - 1;
    int right = 0;
    while (left >= 0 && right < b.size())
    {
        if (a[left] > b[right])
        {
            swap(a[left], b[right]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
}

// optimal solution 2 using gap method(slightly difficult to understand)
// Time Complexity: O((n+m)*log(n+m))
void swapIfGreater(vector<long long> &a, vector<long long> &b, int ind1, int ind2)
{
    if (a[ind1] > b[ind2])
    {
        swap(a[ind1], b[ind2]);
    }
}
void mergeTwoSortedArraysWithoutExtraSpace(vector<long long> &a, vector<long long> &b)
{
    // Write your code here.
    int n = a.size();
    int m = b.size();
    int len = (n + m);
    int gap = (len / 2) + (len % 2); // used to calculate the ceil value of gap
    while (gap > 0)
    {
        int left = 0;
        int right = left + gap;
        while (right < len)
        {
            // arr1 and arr2
            if (left < n && right >= n)
            {
                swapIfGreater(a, b, left, right - n);
            }
            // arr2 and arr2
            else if (left >= n)
            {
                swapIfGreater(b, b, left - n, right - n);
            }
            // arr1 and arr1
            else
            {
                swapIfGreater(a, a, left, right);
            }
            left++;
            right++;
        }
        if (gap == 1)
            break;
        gap = (gap / 2) + (gap % 2);
    }
}