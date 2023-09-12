#include <bits/stdc++.h>
using namespace std;
bool possible(vector<int> &arr, int day, int m, int k)
{
    int cnt = 0;
    int noOfBouquet = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= day)
        {
            cnt++;
        }
        else
        {
            noOfBouquet += (cnt / k);
            cnt = 0;
        }
    }
    noOfBouquet += (cnt / k);
    if (noOfBouquet >= m)
        return true;
    return false;
}
int findMin(vector<int> &arr)
{
    int mini = INT_MAX;
    for (int i = 0; i < arr.size(); i++)
    {
        mini = min(arr[i], mini);
    }
    return mini;
}
int findMax(vector<int> &arr)
{
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        maxi = max(arr[i], maxi);
    }
    return maxi;
}
int roseGarden(vector<int> arr, int k, int m)
{
    // Write your code here
    int low = findMin(arr), high = findMax(arr);
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (possible(arr, mid, m, k))
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