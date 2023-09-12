#include <bits/stdc++.h>
using namespace std;
// space optimization of Fibonacci series using prev and prev2
int main()
{
    int n = 5;
    int prev2 = 0;
    int prev = 1;
    for (int i = 2; i <= n; i++)
    {
        int curri = prev + prev2;
        prev2 = prev;
        prev = curri;
    }
    cout << prev;
    return 0;
}