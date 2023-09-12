#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(nlogn + klogn),  n = size of the given array, k = no. of gas stations to be placed.
// Reason: Insert operation of priority queue takes logn time complexity. O(nlogn) for inserting all the indices with distance values and O(klogn) for placing the gas stations.

// Space Complexity: O(n-1)+O(n-1)
// Reason: The first O(n-1) is for the array to keep track of placed gas stations and the second one is for the priority queue.
long double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size(); // size of array.
    vector<int> howMany(n - 1, 0);
    priority_queue<pair<long double, int>> pq;

    // insert the first n-1 elements into pq
    // with respective distance values:
    for (int i = 0; i < n - 1; i++)
    {
        pq.push({arr[i + 1] - arr[i], i});
    }

    // Pick and place k gas stations:
    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        // Find the maximum section
        // and insert the gas station:
        auto tp = pq.top();
        pq.pop();
        int secInd = tp.second;

        // insert the current gas station:
        howMany[secInd]++;

        long double inidiff = arr[secInd + 1] - arr[secInd];
        long double newSecLen = inidiff / (long double)(howMany[secInd] + 1);
        pq.push({newSecLen, secInd});
    }

    return pq.top().first;
}

int main()
{
    vector<int> arr = {1, 2, 3, 4, 5};
    int k = 4;
    long double ans = minimiseMaxDistance(arr, k);
    cout << "The answer is: " << ans << "\n";
    return 0;
}