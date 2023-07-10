#include<iostream>
using namespace std;
int insert(int arr[],int n,int x,int pos,int cap)
{
	if(n==cap)
	{
		return n;
	}
	int index=pos-1;
	for(int i=n;i>=index;i--)
	{
		arr[i+1]=arr[i];
	}
	arr[index]=x;
	return n+1;
}
int main()
{
	int arr[6]={4,8,10,12,52},x,pos;
	cout<<"Enter the element to be inserted :"<<endl;
	cin>>x;
	cout<<"Enter the position at which you want to insert :"<<endl;
	cin>>pos;
	int new_length=insert(arr,5,x,pos,6);
	cout<<"After insertion :"<<endl;
	for(int i=0;i<new_length;i++)
	{
		cout<<arr[i]<<" ";
	}
	return 0;
}
