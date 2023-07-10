#include <bits/stdc++.h>
using namespace std;
class KthLargest
{
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;

public:
    KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        auto end = nums.begin() + min(k, (int)nums.size());
        pq = priority_queue<int, vector<int>, greater<int>>(nums.begin(), end);
        for (int i = k; i < nums.size(); i++)
        {
            pq.push(nums[i]);
            pq.pop();
        }
    }

    int add(int val)
    {
        pq.push(val);
        if (pq.size() > k)
        {
            pq.pop();
        }
        return pq.top();
    }
};