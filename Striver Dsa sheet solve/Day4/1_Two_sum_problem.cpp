#include <bits/stdc++.h>
using namespace std;
// brute force
// Time Complexity :O(N^2)
string read(int n, vector<int> book, int target)
{
    // Write your code here.
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                continue;
            if (book[i] + book[j] == target)
                return "YES";
        }
    }
    return "NO";
}

// better approach
// Time complexity :O(N* logN)
// space complexity :O(N)
string read(int n, vector<int> book, int target)
{
    // Write your code here.
    unordered_map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int moreNeeded = target - book[i];
        if (mp.find(moreNeeded) != mp.end())
        {
            return "YES";
        }
        mp[book[i]] = i;
    }
    return "NO";
}

// using two pointer approach
// Time Complexity: O(N) + O(N*logN)
string read(int n, vector<int> book, int target)
{
    // Write your code here.
    int left = 0, right = n - 1;
    sort(book.begin(), book.end());
    while (left < right)
    {
        int sum = book[left] + book[right];
        if (sum == target)
            return "YES";
        else if (sum < target)
            left++;
        else
        {
            right--;
        }
    }
    return "NO";
}