#include <bits/stdc++.h>
using namespace std;
class LFUCache
{
public:
    unordered_map<int, vector<int>> mp;
    set<vector<int>> s;
    int cap;
    int counter = 0; // Helps track the latest key on which operation is performed(use for least recently used key)
    LFUCache(int capacity)
    {
        cap = capacity;
    }

    int get(int key)
    {
        if (cap == 0 || mp.find(key) == mp.end())
            return -1;
        counter++;
        int val = mp[key][0];
        int freq = mp[key][1];
        int cnt = mp[key][2];
        auto it = s.find({freq, cnt, key});
        s.erase(it);
        mp[key] = {val, freq + 1, counter};
        s.insert({freq + 1, counter, key});
        return val;
    }

    void put(int key, int value)
    {
        if (cap == 0)
            return;
        counter++;
        if (mp.find(key) != mp.end())
        {
            int val = value;
            int freq = mp[key][1];
            int cnt = mp[key][2];
            auto it = s.find({freq, cnt, key});
            s.erase(it);
            mp[key] = {val, freq + 1, counter};
            s.insert({freq + 1, counter, key});
        }
        else
        {
            if (s.size() >= cap)
            {
                vector<int> it = *s.begin();
                int key1 = it[2];
                mp.erase(key1);
                s.erase(s.begin());
            }
            mp[key] = {value, 1, counter};
            s.insert({1, counter, key});
        }
        return;
    }
};