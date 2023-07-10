#include <bits/stdc++.h>
using namespace std;
// variation 1
// Time Complexity: O(c)
// space complexity :O(1)
int nCr(int n, int r)
{
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}
// This function is a optimal way to calculate the nCr
// variation 2
// Time complexity is O(N)
// space complexity is O(1)
vector<int> generateRow(int row)
{
    int ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1);
    for (int col = 1; col < row; col++)
    {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
// variation 3
//  Time complexity is O(N^2)
//  space complexity is O(1)
vector<vector<int>> generate(int numRows)
{
    vector<vector<int>> ans;
    for (int row = 1; row <= numRows; row++)
    {
        ans.push_back(generateRow(row));
    }
    return ans;
}