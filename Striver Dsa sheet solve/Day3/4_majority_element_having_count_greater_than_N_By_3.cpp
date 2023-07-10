#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(N) + O(N)
// Space Complexity: O(1)
vector<int> majorityElement(vector<int> v)
{
    // Write your code here
    vector<int> ans;
    int ele1 = 0, ele2 = 0;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (cnt1 == 0 && ele2 != v[i])
        {
            cnt1 = 1;
            ele1 = v[i];
        }
        else if (cnt2 == 0 && ele1 != v[i])
        {
            cnt2 = 1;
            ele2 = v[i];
        }
        else if (v[i] == ele1)
        {
            cnt1++;
        }
        else if (v[i] == ele2)
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }
    }
    int cntc1 = 0, cntc2 = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == ele1)
            cntc1++;
        if (v[i] == ele2)
            cntc2++;
    }
    int mini = (v.size() / 3) + 1;
    if (cntc1 >= mini)
        ans.push_back(ele1);
    if (cntc2 >= mini)
        ans.push_back(ele2);
    return ans;
}