#include<iostream>
using namespace std;
void left_rotate_by_1(int arr[],int n)
{
	int temp=arr[0];
	for(int i=1;i<n;i++)
	{
		arr[i-1]=arr[i];
	}
	arr[n-1]=temp;
}
//takes O(nd) time complexity
void left_rotate_1(int arr[],int n,int d)
{
	for(int i=0;i<d;i++)
	{
		left_rotate_by_1(arr,n);
	}
}
//takes O(n) time and auxillary space=O(d)
void left_rotate_2(int arr[],int n,int d)
{
	int temp[d];
	for(int i=0;i<d;i++)
	{
		temp[i]=arr[i];
	}
	for(int i=d;i<n;i++)
	{
		arr[i-d]=arr[i];
	}
	for(int i=0;i<d;i++)
	{
		arr[n-d+i]=temp[i];
	}
	
}
void reverse(int arr[],int low,int high)
{
	int temp;
	while(low<high)
	{
		temp=arr[low];
		arr[low]=arr[high];
		arr[high]=temp;
		low++;
		high--;
	}
}
//takes O(n) time auxillary space=O(1)
void left_rotate_3(int arr[],int n,int d)
{
	reverse(arr,0,d-1);
	reverse(arr,d,n-1);
	reverse(arr,0,n-1);
}
int main()
{
	int arr[]={1,2,3,4,5};
	left_rotate_3(arr,5,2);
	cout<<"Left rotate array by given number of times:"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
