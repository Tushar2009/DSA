#include <bits/stdc++.h>
using namespace std;
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};
bool static comparator(Job j1, Job j2)
{
    return j1.profit > j2.profit;
}
vector<int> JobScheduling(Job arr[], int n)
{
    // your code here
    sort(arr, arr + n, comparator);
    int maxi = arr[0].dead;
    for (int i = 1; i < n; i++)
    {
        maxi = max(maxi, arr[i].dead);
    }
    vector<int> slot(maxi + 1, -1);
    int maxprofit = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = arr[i].dead; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                maxprofit += arr[i].profit;
                count++;
                break;
            }
        }
    }
    return {count, maxprofit};
}