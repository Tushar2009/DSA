#include<iostream>
using namespace std;
bool checkEquilibrium(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		int l_sum=0,r_sum=0;
		for(int j=0;j<i;j++)
		{
			l_sum+=arr[j];
		}
		for(int k=i+1;k<n;k++)
		{
			r_sum+=arr[k];
		}
		if(l_sum==r_sum)
		{
			return true;
		}
	}
	return false;
}
//efficient way
bool checkEquilibrium2(int arr[], int n)
{
	int sum = 0;

	for(int i = 0; i < n; i++)
	{
		sum += arr[i];
	}

	int l_sum = 0;

	for(int i = 0; i < n; i++)
	{
		if(l_sum == sum - arr[i])
			return true;

		l_sum += arr[i];

		sum -= arr[i];
	}

	return false;
}
int main()
{
	int arr[] = {3, 4, 8, -9, 20, 6}, n = 6;
	cout<<"Equilibrium point is there :"<<checkEquilibrium2(arr,n)<<endl;
}
