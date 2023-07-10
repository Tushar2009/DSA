#include<iostream>
using namespace std;
int largestele(int arr[],int n)
{
	int max=0; // max is index of maximum element
	for(int i=1;i<n;i++)
	{
		if(arr[i]>arr[max])
		{
			max=i;
		}
	}
	return max;
}
// it searches the 2nd largest element in order of O(n) time
int second_largest_efficient(int arr[],int n)
{
	int res=-1,largest=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]>arr[largest])
		{
			res=largest;
			largest=i;
		}
		// example :arr[] =12 7 12 9
		else if(arr[i]!=arr[largest])
		{
			if(res==-1 || arr[i]>arr[res])
			{
				res=i;
			}
		}
	}
	return res;
}
int secondlargest(int arr[],int n)
{
	int res=-1;
	int largest=largestele(arr,n);
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=arr[largest])
		{
			if(res==-1)
			{
				res=i;
			}
			else if(arr[i]>arr[res])
			{
				res=i;
			}
		}
	}
	return res;
	
}
int main()
{
	int arr[]={7,29,63,98,105};
	int result=second_largest_efficient(arr,5);
	cout<<"2nd Largest element in an array is :"<<arr[result]<<endl;
}
