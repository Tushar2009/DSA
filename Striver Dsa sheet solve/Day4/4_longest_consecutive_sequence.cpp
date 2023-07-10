#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n)
{
    // Write your code here.
    unordered_set<int> s;
    for (int i = 0; i < n; i++)
    {
        s.insert(arr[i]);
    }
    int ans = INT_MIN;
    for (auto num : s)
    {
        if (!s.count(num - 1))
        {
            int current_ele = num;
            int counter = 1;
            while (s.count(current_ele + 1))
            {
                current_ele++;
                counter++;
            }
            ans = max(ans, counter);
        }
    }
    return ans;
}