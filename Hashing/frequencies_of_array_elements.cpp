#include<bits/stdc++.h>
using namespace std;
 //naive method with time complexity is O(n^2)
void countFreq(int arr[], int n)
{
    // Mark all array elements as not visited
    vector<bool> visited(n, false);
 
    // Traverse through array elements and
    // count frequencies
    for (int i = 0; i < n; i++) {
 
        // Skip this element if already processed
        if (visited[i] == true)
            continue;
 
        // Count frequency
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                visited[j] = true;
                count++;
            }
        }
        cout << arr[i] << " " << count << endl;
    }
}
//efficient way
// Time complexity is theta(n)
// space complexity is O(n)
void print_frequencies(int arr[],int n)
{
    unordered_map<int,int> m;
    for(int i = 0; i < n; i++)
    {
        m[arr[i]]++;
    }
    for(auto x:m)
    {
        cout<<x.first<<" "<<x.second<<endl;
    }
}
int main()
{
    int arr[]={10,12,10,15,10,20,12,12};
    print_frequencies(arr,8);
    return 0;
}