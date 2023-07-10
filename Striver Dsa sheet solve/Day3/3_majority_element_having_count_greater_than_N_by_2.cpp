#include <bits/stdc++.h>
using namespace std;
// using hash map(better solution)
// Time Complexity: O(N*logN) + O(N)
// Space Complexity: O(N)
int majorityElement(int a[], int size)
{

    // your code here
    map<int, int> mp;
    for (int i = 0; i < size; i++)
    {
        mp[a[i]]++;
    }
    int result = size / 2;
    for (auto it : mp)
    {
        if (it.second > result)
            return it.first;
    }
    return -1;
}
// Moore's voting algorithm
// Time Complexity O(n)
// Space Complexity: O(1)
int majorityElement(vector<int> v)
{
    // Write your code here
    int ele = 0;
    int cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (cnt == 0)
        {
            cnt = 1;
            ele = v[i];
        }
        else if (v[i] == ele)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    int cnt1 = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == ele)
            cnt1++;
    }
    if (cnt1 > v.size() / 2)
        return ele;
    return -1;
}