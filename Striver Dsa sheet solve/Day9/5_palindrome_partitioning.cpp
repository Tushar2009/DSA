#include <bits/stdc++.h>
using namespace std;
bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
        {
            return false;
        }
    }
    return true;
}
void f(int ind, vector<string> &path, vector<vector<string>> &res, string s)
{
    if (ind == s.size())
    {
        res.push_back(path);
        return;
    }
    for (int i = ind; i < s.size(); i++)
    {
        if (isPalindrome(s, ind, i))
        {
            path.push_back(s.substr(ind, i - ind + 1));
            f(i + 1, path, res, s);
            path.pop_back();
        }
    }
}
vector<vector<string>> partition(string s)
{
    vector<vector<string>> res;
    vector<string> path;
    f(0, path, res, s);
    return res;
}