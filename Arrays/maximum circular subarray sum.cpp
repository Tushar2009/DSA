#include<iostream>
using namespace std;
//kadane's algo
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
int max_circular_sub_array_sum(int arr[],int n)
{
	int maxNormal=max_sub_array_sum(arr,n);
	if(maxNormal<0)
	{
		return maxNormal;
	}
	int arr_sum=0;
	for(int i=0;i<n;i++)
	{
		arr_sum+=arr[i];
		arr[i]=-arr[i];
	}
	int maxCircular=arr_sum+max_sub_array_sum(arr,n);
	return max(maxCircular,maxNormal);
}
int maxcircularsum(int arr[],int n)
{
	int res=arr[0];
	for(int i=0;i<n;i++)
	{
		int curr_sum=arr[i];
		int curr_max=arr[i];
		for(int j=1;j<n;j++)
		{
			int index=(i+j)%n;
			curr_sum+=arr[index];
			curr_max=max(curr_max,curr_sum);
		}
		res=max(res,curr_max);
	}
	return res;
}
int main()
{
	int arr[]={8,-4,3,-5,4};
	cout<<"Maximum sum of circular sub-array :"<<maxcircularsum(arr,5)<<endl;
}
