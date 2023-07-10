//Leaders in an array problem
#include<iostream>
using namespace std;

// leader of an array means on Right side of an element all elements are smaller
void leaders_1(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		bool flag=true;
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]<=arr[j])
			{
				flag=false;
				break;
			}
		}
		if(flag==true)
		{
			cout<<arr[i]<<" ";
		}
	}
}
void leaders_2(int arr[],int n)
{
	int current_leader=arr[n-1];
	cout<<current_leader<<" ";
	for(int i=n-2;i>=0;i--)
	{
		if(current_leader<arr[i])
		{
			current_leader=arr[i];
			cout<<current_leader<<" ";
		}
	}
}
int main()
{
	int arr[]={7,10,4,10,6,5,2};
	cout<<"leaders present in array are :"<<endl;
	leaders_1(arr,7);
}
