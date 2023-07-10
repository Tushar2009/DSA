#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> get_max(int arr[], int n)
{
   stack<int> st;
   int left[n + 1];  // previous smaller
   int right[n + 1]; // next smaller
   for (int i = 0; i < n; i++)
   {
      left[i] = -1;
      right[i] = n;
   }
   // this loop is used to store the previous smaller elememt's index of each element and store it in left[]
   for (int i = 0; i < n; i++)
   {
      while (!st.empty() && arr[st.top()] >= arr[i])
      {
         st.pop();
      }
      if (!st.empty())
      {
         left[i] = st.top();
      }
      st.push(i);
   }
   while (!st.empty())
   {
      st.pop();
   }
   // this loop is used to store the next smaller elememt's index of each element and store it in right[]
   for (int i = n - 1; i >= 0; i--)
   {
      while (!st.empty() && arr[st.top()] >= arr[i])
      {
         st.pop();
      }
      if (!st.empty())
      {
         right[i] = st.top();
      }
      st.push(i);
   }
   vector<int> ans(n + 1);
   for (int i = 0; i < n; i++)
   {
      ans[i] = 0;
   }
   // updating the ans array with values which are smaller in that particular range
   for (int i = 0; i < n; i++)
   {
      int len = right[i] - left[i] - 1;
      ans[len] = max(ans[len], arr[i]);
   }

   // rest
   for (int i = n - 1; i >= 1; i--)
   {
      ans[i] = max(ans[i], ans[i + 1]);
   }
   vector<int> res(n);
   for (int i = 1; i <= n; i++)
   {
      res[i - 1] = ans[i];
   }
   return res;
}
int main()
{
   int arr[] = {10, 20, 30, 50, 10, 70, 30};
   vector<int> res = get_max(arr, 7);
   for (int i = 0; i < 7; i++)
   {
      cout << res[i] << " ";
   }
   return 0;
}