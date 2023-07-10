#include <bits/stdc++.h>
using namespace std;
// Brute force solution
// Time Complexity: O(N*N)
// Space Complexity: O(1)
int trap(vector<int> &arr)
{
    int n = arr.size();
    int waterTrapped = 0;
    for (int i = 0; i < n; i++)
    {
        int j = i;
        int leftMax = 0, rightMax = 0;
        while (j >= 0)
        {
            leftMax = max(leftMax, arr[j]);
            j--;
        }
        j = i;
        while (j < n)
        {
            rightMax = max(rightMax, arr[j]);
            j++;
        }
        waterTrapped += min(leftMax, rightMax) - arr[i];
    }
    return waterTrapped;
}
// better solution
// Time Complexity: O(3*N)
// Space Complexity: O(N)+O(N) for prefix and suffix arrays.
int trap(vector<int> &arr)
{
    int n = arr.size();
    int prefix[n], suffix[n];
    prefix[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefix[i] = max(prefix[i - 1], arr[i]);
    }
    suffix[n - 1] = arr[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        suffix[i] = max(suffix[i + 1], arr[i]);
    }
    int waterTrapped = 0;
    for (int i = 0; i < n; i++)
    {
        waterTrapped += min(prefix[i], suffix[i]) - arr[i];
    }
    return waterTrapped;
}
// optimal solution
// Time complexity :O(n)
// space complexity :O(1)
int trap(vector<int> &height)
{
    int n = height.size();
    int left = 0, right = n - 1;
    int leftmax = 0;
    int rightmax = 0;
    int res = 0;
    while (left <= right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] > leftmax)
                leftmax = height[left];
            else
                res += leftmax - height[left];
            left++;
        }
        else
        {
            if (height[right] > rightmax)
                rightmax = height[right];
            else
                res += rightmax - height[right];
            right--;
        }
    }
    return res;
}