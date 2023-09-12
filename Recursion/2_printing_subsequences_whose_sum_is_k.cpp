#include <bits/stdc++.h>
using namespace std;
// print subsequence whose sum is k
void printF(int index, vector<int> &res, int s, int sum, int arr[], int n)
{
    if (index == n)
    {
        if (s == sum)
        {
            for (auto x : res)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        return;
    }
    res.push_back(arr[index]);
    s += arr[index];
    printF(index + 1, res, s, sum, arr, n);
    res.pop_back();
    s -= arr[index];
    printF(index + 1, res, s, sum, arr, n);
}

// print any subsequence whose sum is equal to k
//  bool printF(int index,vector<int> &res,int s,int sum,int arr[],int n)
//  {
//      if(index==n)
//      {
//          // condition satisfied
//          if(s==sum)
//          {
//              for(auto x:res)
//              {
//                  cout<<x<<" ";
//              }
//              cout<<endl;
//              return true;
//          }
//          // condition not satisfied
//          return false;
//      }
//      res.push_back(arr[index]);
//      s+=arr[index];
//      if(printF(index+1,res,s,sum,arr,n)==true)
//      {
//          return true;
//      }
//      res.pop_back();
//      s-=arr[index];
//      if(printF(index+1,res,s,sum,arr,n)==true)
//      {
//          return true;
//      }
//      return false;
//  }

// count the subsequences with sum k
int printF(int index, int s, int sum, int arr[], int n)
{
    // condition not satisfied
    // strictly done if array contains positives only
    if (s > sum)
        return 0;
    if (index == n)
    {
        // condition satisfied
        if (s == sum)
        {
            return 1;
        }
        // condition not satisfied
        return 0;
    }
    s += arr[index];
    int left = printF(index + 1, s, sum, arr, n);

    s -= arr[index];
    int right = printF(index + 1, s, sum, arr, n);
    return left + right;
}
int main()
{
    int arr[] = {1, 2, 1};
    int sum = 2;
    int n = 3;
    // vector<int> res;
    cout << printF(0, 0, sum, arr, n);
    return 0;
}