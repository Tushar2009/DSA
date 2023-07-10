#include <bits/stdc++.h>
using namespace std;
struct triplet
{
    int val, aPos, vPos;
    triplet(int v, int ap, int vp)
    {
        val = v;
        aPos = ap;
        vPos = vp;
    }
};
struct mycmp
{
    bool operator()(triplet &t1, triplet &t2)
    {
        return t1.val > t2.val;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>> &kArrays, int k)
{
    // Write your code here.
    vector<int> res;
    priority_queue<triplet, vector<triplet>, mycmp> pq;
    for (int i = 0; i < kArrays.size(); i++)
    {
        pq.push(triplet(kArrays[i][0], i, 0));
    }
    while (!pq.empty())
    {
        triplet cur = pq.top();
        pq.pop();
        res.push_back(cur.val);
        int apos = cur.aPos;
        int vpos = cur.vPos;
        if (vpos + 1 < kArrays[apos].size())
        {
            triplet t(kArrays[apos][vpos + 1], apos, vpos + 1);
            pq.push(t);
        }
    }
    return res;
}