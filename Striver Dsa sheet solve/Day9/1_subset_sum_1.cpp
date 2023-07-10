#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(2^n)+O(2^n log(2^n))
// Each index has two ways. You can either pick it up or not pick it.
// So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).
// Space Complexity: O(2^n)
void solve(int index, int sum, vector<int> &res, vector<int> arr, int N)
{
    if (index == N)
    {
        res.push_back(sum);
        return;
    }
    // pick
    solve(index + 1, sum + arr[index], res, arr, N);
    // not pick
    solve(index + 1, sum, res, arr, N);
}
vector<int> subsetSums(vector<int> arr, int N)
{
    // Write Your Code here
    vector<int> res;
    solve(0, 0, res, arr, N);
    return res;
}