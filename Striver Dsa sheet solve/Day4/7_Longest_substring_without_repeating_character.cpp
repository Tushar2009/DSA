#include <bits/stdc++.h>
using namespace std;
// better solution
// Time complexity :O(2*n)
// space complexity :O(n)
int solve(string str)
{

    if (str.size() == 0)
        return 0;
    int maxans = INT_MIN;
    unordered_set<int> set;
    int l = 0;
    for (int r = 0; r < str.length(); r++) // outer loop for traversing the string
    {
        if (set.find(str[r]) != set.end()) // if duplicate element is found
        {
            while (l < r && set.find(str[r]) != set.end())
            {
                set.erase(str[l]);
                l++;
            }
        }
        set.insert(str[r]);
        maxans = max(maxans, r - l + 1);
    }
    return maxans;
}
// optimal solution
// Time complexity :O(n)
// space complexity :O(n)
int uniqueSubstrings(string input)
{
    // Write your code here
    int left = 0, right = 0;
    int len = 0;
    map<char, int> mp;
    int n = input.size();
    while (right < n)
    {
        if (mp.find(input[right]) != mp.end())
        {
            left = max(mp[input[right]] + 1, left);
        }
        mp[input[right]] = right;
        len = max(len, right - left + 1);
        right++;
    }

    return len;
}