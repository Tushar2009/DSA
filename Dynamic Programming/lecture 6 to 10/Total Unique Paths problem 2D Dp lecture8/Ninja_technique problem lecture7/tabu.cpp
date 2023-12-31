#include <bits/stdc++.h>
using namespace std;
int f(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    for (int day = 1; day < points.size(); day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (last != task)
                {
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[day][last];
}
int main()
{
    vector<vector<int>> points = {{2, 1, 3},
                                  {3, 4, 6},
                                  {10, 1, 6},
                                  {8, 3, 7}};
    int n = 4;
    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    cout << f(n - 1, 3, points, dp);
}