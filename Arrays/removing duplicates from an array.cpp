#include<iostream>
using namespace std;
int remove_duplicates(int arr[],int n)
{
	int res=1;
	for(int i=1;i<n;i++)
	{
		if(arr[i]!=arr[res-1])
		{
			arr[res]=arr[i];
			res++;
		}
	}
	return res;
}
int main()
{
	int arr[]={10,10,10,20,20,20,20,30,30,30};
	int result=remove_duplicates(arr,10);
	cout<<"Without Duplicates :"<<endl;
	for(int i=0;i<result;i++)
	{
		cout<<arr[i]<<" ";
	}
}
