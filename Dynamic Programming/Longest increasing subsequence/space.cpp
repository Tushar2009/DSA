#include <bits/stdc++.h>
using namespace std;
int longestIncreasingSubsequence(int arr[], int n)
{
    // Write Your Code here
    vector<int> next(n + 1, 0), cur(n + 1, 0);

    for (int ind = n - 1; ind >= 0; ind--)
    {
        for (int prev = ind - 1; prev >= -1; prev--)
        {
            // not-take case
            int len = 0 + next[prev + 1];

            // take case
            if (prev == -1 || arr[ind] > arr[prev])
            {
                len = max(len, 1 + next[ind + 1]);
            }
            cur[prev + 1] = len;
        }
        next = cur;
    }

    return next[-1 + 1];
}