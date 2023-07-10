#include<iostream>
using namespace std;
//logic: is that ki agar new element aaya aur vo different hua previous ka aur first element ka then start flipping 
//and stop when agin new element appears which is equal to first element
void consecutive_flips(int arr[],int n)
{
	for(int i=1;i<n;i++)
	{
		if(arr[i]!=arr[i-1])
		{
			if(arr[i]!=arr[0])
			{
				cout<<"from "<<i<<" to ";
			}
			else
			{
				cout<<(i-1)<<endl;
			}
		}
	}
	if(arr[n-1]!=arr[0])
	{
		cout<<n-1<<endl;
	}
}
int main()
{
	int arr[]={0,0,1,1,0,0,1,1,1,0,0,0,0};
	consecutive_flips(arr,13);
}
