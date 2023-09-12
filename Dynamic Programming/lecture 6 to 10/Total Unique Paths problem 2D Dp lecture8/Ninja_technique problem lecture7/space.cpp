#include <bits/stdc++.h>
using namespace std;
int f(int day, int last, vector<vector<int>> &points, vector<int> &prev)
{
    for (int day = 1; day < points.size(); day++)
    {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (last != task)
                {
                    temp[last] = max(temp[last], points[day][task] + prev[task]);
                }
            }
        }
        prev = temp;
    }
    return prev[last];
}
int main()
{
    vector<vector<int>> points = {{1, 2, 5},
                                  {3, 1, 1},
                                  {3, 3, 3}};
    int n = 3;
    vector<int> prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));
    cout << f(n - 1, 3, points, prev);
}