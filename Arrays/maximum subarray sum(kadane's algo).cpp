#include<iostream>
#include<cmath>
using namespace std;
//efficient way
//logic:In this we are checking the maximumfinding+current element is maximum or current element is maximum
// basically we are seeing that including the current element gives large sum or not 
//else current element alone has maximum sum of subarray
int max_sub_array_sum(int arr[],int n)
{
	int res=arr[0];
	int maxfinding=arr[0];
	for(int i=1;i<n;i++)
	{
		maxfinding=max(maxfinding+arr[i],arr[i]);
		res=max(maxfinding,res);
	}
	return res;
}
int max_sub_array_sum2(int arr[],int n)
{
	int res=arr[0];
	for(int i=1;i<n;i++)
	{
		int curr=0;
	    for(int j=i;j<n;j++)
	    {
	    	curr=curr+arr[j];
	    	res=max(curr,res);
	    	
		}
	}
	return res;
}
int main()
{
	int arr[]={-3,8,-2,4,-5,6};
	cout<<"Maximum sum of sub-array :"<<max_sub_array_sum2(arr,6)<<endl;
}

