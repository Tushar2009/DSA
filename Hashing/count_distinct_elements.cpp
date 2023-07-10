#include<bits/stdc++.h>
using namespace std;
//efficient way
// Time complexity is O(n)
// aux space is O(n)
int count_distinct(int arr[],int n)
{
    unordered_set<int> s;
    for(int i=0;i<n;i++)
    {
        s.insert(arr[i]);
    }
    return s.size();
}
int main()
{
    int arr[]={10,10,10};
    cout<<"No. of distinct elements in array are :"<<count_distinct(arr,3)<<endl;
    return 0;
}