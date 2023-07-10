#include<iostream>
using namespace std;
int  max_consecutive_sum(int arr[],int n,int k)
{
	int sum,res=INT_MIN;
	for(int i=0;i+k-1<n;i++)
	{
		sum=0;
		for(int j=0;j<k;j++)
		{
			sum=sum+arr[i+j];
		}
		res=max(sum,res);
	}
	return res;
}
//sliding window technique = means adding one element and deleting one element
int max_consecutive_sum2(int arr[],int n,int k)
{
	int curr_sum=0;
	for(int i=0;i<k;i++)
	{
		curr_sum+=arr[i];
		
	}
	int max_sum=curr_sum;
	for(int i=k;i<n;i++)
	{
		curr_sum+=arr[i]-arr[i-k];
		max_sum=max(max_sum,curr_sum);
		
	}
	return max_sum;
}
bool max_consecutive_sum3(int arr[],int n,int sum)
{
	int curr_sum=arr[0],s=0;   // s=start,e=end
	for(int e=1;e<n;e++)
	{
		while(curr_sum>sum && s<e-1)
		{
			curr_sum=curr_sum-arr[s];
			s++;
		}
		if(curr_sum==sum)
		{
			return true;
		}
		if(e<n)
		{
			curr_sum+=arr[e];
		}
	}
	return false;
}
int main()
{
	int arr[]={1,8,30,-5,20,7};
	cout<<"Maximum consecutive numbers sum in an array is present:"<<max_consecutive_sum2(arr,6,45)<<endl;
}
