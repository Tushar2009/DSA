#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> a;
    a.push_back(2);
    a.push_back(1);
    a.push_back(4);
    a.push_back(9);
    int n = 4;
    int prev2 = 0;
    int prev = a[0];
    for (int i = 1; i < n; i++)
    {
        int take = a[i];
        if (i > 1)
            take += prev2;
        int not_take = 0 + prev;
        int curri = max(take, not_take);
        prev2 = prev;
        prev = curri;
    }
    cout << prev;

    return 0;
}