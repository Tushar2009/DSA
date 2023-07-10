#include <bits/stdc++.h>
using namespace std;
struct Item
{
    int value;
    int weight;
};
// Time Complexity: O(n log n + n). O(n log n) to sort the items
// and O(n) to iterate through all the items for calculating the answer.
class Solution
{
public:
    // Function to get the maximum total value in the knapsack.
    bool static comparator(Item a, Item b)
    {
        double r1 = (double)a.value / (double)a.weight;
        double r2 = (double)b.value / (double)b.weight;
        return r1 > r2;
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr + n, comparator);
        double maxivalue = 0.0;
        int currentW = 0;
        for (int i = 0; i < n; i++)
        {
            if (currentW + arr[i].weight <= W)
            {
                maxivalue += arr[i].value;
                currentW += arr[i].weight;
            }
            else
            {
                int remain = W - currentW;
                double add = (arr[i].value / (double)arr[i].weight) * (double)remain;
                maxivalue += add;
                break;
            }
        }
        return maxivalue;
    }
};