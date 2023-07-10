#include <bits/stdc++.h>
using namespace std;
// Time complexity :O(n)
// space complexity :O(m)
void lpsArray(string str, vector<int> &lps)
{
    int n = str.length(), len = 0;
    lps[len] = 0;
    int i = 1;
    while (i < n)
    {
        if (str[i] == str[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
}
int strStr(string s, string tar)
{
    int n = s.length();
    int m = tar.length();
    vector<int> lps(m + 1);
    lpsArray(tar, lps);
    int i = 0, j = 0; // i for s, j for tar
    while (i < n)
    {
        if (s[i] == tar[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }

        if (j == m)
            return (i - m);
    }

    return -1;
}