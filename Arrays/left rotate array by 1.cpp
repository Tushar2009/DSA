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
int main()
{
	int arr[]={1,2,3,4,5};
	left_rotate_by_1(arr,5);
	cout<<"Left rotate array by one:"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
