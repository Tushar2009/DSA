#include <bits/stdc++.h>
using namespace std;
int ceilIdx(int tail[], int l, int r, int key)
{
    while (l < r)
    {
        int m = l + (r - l) / 2;
        if (tail[m] >= key)
            r = m;
        else
            l = m + 1;
    }

    return r;
}
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    int temp[n];
    temp[0] = arr[0];
    int len = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > temp[len - 1])
        {
            temp[len] = arr[i];
            len++;
        }
        else
        {
            int ind = ceilIdx(temp, 0, len, arr[i]);
            temp[ind] = arr[i];
        }
    }
    return len;
}