#include<iostream>
using namespace std;
int Delete(int arr[],int x,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		if(arr[i]==x)
		{
			break;
		}
	}
	if(i==n)
	{
		return n;
	}
	for(int j=i;j<n-1;j++)
	{
		arr[j]=arr[j+1];
	}
	return n-1;
}
int main()
{
	int arr[]={4,5,17,25,63};
	int new_length=Delete(arr,18,5);
	cout<<"array after deletion :"<<endl;
	for(int i=0;i<new_length;i++)
	{
		cout<<arr[i]<<" ";
	}
}
