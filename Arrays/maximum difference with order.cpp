#include <iostream>
#include <cmath>
using namespace std;
int maxDiff(int arr[], int n)
{
	int res = arr[1] - arr[0];
	for(int i = 0; i < n - 1; i++)
	{
		for(int j = i + 1; j < n; j++)
		{
			res = max(res, arr[j] - arr[i]);
		}
	}
	return res;
}
int maxDiff2(int arr[],int n)
{
	int minval=arr[0];
	int res=arr[1]-arr[0];
	for(int i=0;i<n;i++)
	{
		res=max(res,arr[i]-minval);
		minval=min(minval,arr[i]);
	}
	return res;
}
int main() {
      int arr[] = {2, 3, 10, 6, 4, 8, 1}, n = 7;
      cout<<"The maximum difference with order is :";
      cout<<maxDiff2(arr, n);
    
}
