#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(nlogn) Sorting takes O(nlogn) and traversal of arrays takes O(n) so overall time complexity is O(nlogn).
// Space complexity: O(1)
int findPlatform(int arr[], int dep[], int n)
{
    // Your code here
    sort(arr, arr + n);
    sort(dep, dep + n);
    int plat_needed = 1, result = 1;
    int i = 1, j = 0;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            plat_needed++;
            i++;
        }
        else if (arr[i] > arr[j])
        {
            plat_needed--;
            j++;
        }
        result = max(result, plat_needed);
    }
    return result;
}