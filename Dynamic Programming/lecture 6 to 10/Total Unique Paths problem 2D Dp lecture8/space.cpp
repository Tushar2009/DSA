#include <bits/stdc++.h>
using namespace std;
int main()
{
    int m = 3, n = 3;
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> temp(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                temp[j] = 1;
            else
            {
                int up = 0;
                int left = 0;
                if (i > 0)
                    up = prev[j];
                if (j > 0)
                    left = temp[j - 1];
                temp[j] = up + left;
            }
        }
        prev = temp;
    }
    cout << "Total no. of ways :" << prev[n - 1];
}