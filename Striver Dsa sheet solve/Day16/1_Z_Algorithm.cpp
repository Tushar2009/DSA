#include <bits/stdc++.h>
using namespace std;
int strStr(string haystack, string needle)
{
    int n = haystack.length();
    int m = needle.length();
    string z = needle + '#' + haystack;
    int i = 0;
    vector<int> h;
    for (; i < z.length(); i++)
    {
        if (i <= m)
            h.push_back(0);
        else
        {
            int left = 0, right = 0;
            if (z[left] == z[i])
            {
                right = i;
                while (z[left] == z[right] && right < z.length())
                {
                    left++;
                    right++;
                }
            }
            h.push_back(left);
        }
    }
    for (int j = 0; j < z.length(); j++)
    {
        if (h[j] == m)
            return j - m - 1;
    }
    return -1;
}