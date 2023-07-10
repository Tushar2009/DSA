#include<iostream>
using namespace std;
void reverse(int arr[],int n)
{
	int low=0,high=n-1,temp;
	while(low<high)
	{
		temp=arr[low];
		arr[low]=arr[high];
		arr[high]=temp;
		low++;
		high--;
	}
	
}
int main()
{
	int arr[]={10,20,50,40,100};
	reverse(arr,5);
	cout<<"Reversed array is :"<<endl;
	for(int i=0;i<5;i++)
	{
		cout<<arr[i]<<" ";
	}
}
