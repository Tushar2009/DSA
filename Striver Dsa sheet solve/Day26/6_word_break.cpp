#include <bits/stdc++.h>
using namespace std;
int wordBreak(int ind, string s, unordered_set<string> &wordDict, vector<int> &dp)
{
    if (ind == s.size())
        return 1;
    if (dp[ind] != -1)
        return dp[ind];
    string temp;
    for (int j = ind; j < s.size(); j++)
    {
        temp += s[j];
        if (wordDict.find(temp) != wordDict.end())
        {
            if (wordBreak(j + 1, s, wordDict, dp))
                return dp[ind] = 1;
        }
    }
    return dp[ind] = 0;
}
bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> set(wordDict.begin(), wordDict.end());
    vector<int> dp(s.size(), -1);
    return wordBreak(0, s, set, dp);
}