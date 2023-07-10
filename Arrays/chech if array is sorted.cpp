#include<iostream>
using namespace std;
bool issorted(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		if(arr[i]<arr[i-1])
		{
			return false;
		}
	}
	return true;
}
int main()
{
	int arr[]={7,18,24,42,64};
	bool result=issorted(arr,5);
	if(result==true)
	{
		cout<<"Array is sorted "<<endl;
	}
	else
	{
		cout<<"array is not sorted "<<endl;
	}
}
