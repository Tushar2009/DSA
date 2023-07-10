#include <bits/stdc++.h>
using namespace std;
// Time complexity : Overall : O(n) +O(n log n) + O(n) ~O(n log n)
//  space complexity :O(n)
class meet
{
public:
    int start;
    int end;
    int pos;
};
class Solution
{
public:
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    static bool comparator(meet m1, meet m2)
    {
        if (m1.end < m2.end)
            return true;
        else if (m1.end > m2.end)
            return false;
        else if (m1.pos < m2.pos)
            return true;
        return false;
    }
    int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        meet m[n];
        for (int i = 0; i < n; i++)
        {
            m[i].start = start[i];
            m[i].end = end[i];
            m[i].pos = i + 1;
        }
        sort(m, m + n, comparator);
        vector<int> ans;
        int limit = m[0].end;
        ans.push_back(m[0].pos);
        for (int i = 1; i < n; i++)
        {
            if (m[i].start > limit)
            {
                limit = m[i].end;
                ans.push_back(m[i].pos);
            }
        }
        return ans.size();
    }
};