#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> height;
    height.push_back(10);
    height.push_back(20);
    height.push_back(30);
    height.push_back(10);
    int prev2 = 0;
    int prev = 0;
    for (int i = 1; i < height.size(); i++)
    {

        int left = prev + abs(height[i] - height[i - 1]);
        int right = INT_MAX;
        if (i > 1)
            right = prev2 + abs(height[i] - height[i - 2]);
        int curri = min(left, right);
        prev2 = prev;
        prev = curri;
    }
    cout << prev;
    return 0;
}