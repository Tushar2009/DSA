#include <bits/stdc++.h>
using namespace std;
class MedianFinder
{
    priority_queue<int> s;
    priority_queue<int, vector<int>, greater<int>> g;

public:
    MedianFinder()
    {
        // priority_queue<int> s;
        // priority_queue<int,vector<int>,greater<int>> g;
    }

    void addNum(int num)
    {
        if (s.size() == 0 || s.top() >= num)
            s.push(num);
        else
            g.push(num);
        if (s.size() > (g.size() + 1))
        {
            g.push(s.top());
            s.pop();
        }
        else
        {
            if (g.size() > s.size())
            {
                s.push(g.top());
                g.pop();
            }
        }
    }

    double findMedian()
    {
        if (s.size() == g.size())
            return s.top() / 2.0 + g.top() / 2.0;
        else
        {
            return s.top() * 1.0;
        }
    }
};