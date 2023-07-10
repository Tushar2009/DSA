#include <bits/stdc++.h>
using namespace std;
int wordLadderLength(string startWord, string targetWord, vector<string> &wordList)
{
    // Code here
    queue<pair<string, int>> q;
    q.push({startWord, 1});
    unordered_set<string> st(wordList.begin(), wordList.end());
    st.erase(startWord);
    // O(N*word.length*26)
    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();
        if (word == targetWord)
            return steps;
        // O(word.length*26*logN for set)
        for (int i = 0; i < word.size(); i++)
        {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;
                // it means it exists in the set
                if (st.find(word) != st.end())
                {
                    st.erase(word);
                    q.push({word, steps + 1});
                }
            }
            word[i] = original;
        }
    }
    return 0;
}