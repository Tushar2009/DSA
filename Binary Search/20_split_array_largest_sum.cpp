#include <bits/stdc++.h>
using namespace std;
int countStudents(vector<int> &arr, int pages)
{
    int n = arr.size(); // size of array.
    int students = 1;
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++)
    {
        if (pagesStudent + arr[i] <= pages)
        {
            // add pages to current student
            pagesStudent += arr[i];
        }
        else
        {
            // add pages to next student
            students++;
            pagesStudent = arr[i];
        }
    }
    return students;
}
int findPages(vector<int> &arr, int N, int M)
{
    // Write your code here.
    if (M > N)
        return -1;
    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);
    int ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (countStudents(arr, mid) > M)
        {
            low = mid + 1;
        }
        else
        {
            ans = mid;
            high = mid - 1;
        }
    }
    return ans;
}
int splitArray(vector<int> &nums, int k)
{
    return findPages(nums, nums.size(), k);
}