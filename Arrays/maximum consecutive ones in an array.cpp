#include<iostream>
using namespace std;
//efficient way
// logic:if any 0 comes between we make the current as 0 else increment the current and return the max result
int maxConsecutiveOnes(int arr[],int n)
{
	int curr=0;
	int res=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]==0)
		{
			curr=0;
		}
		else
		{
			curr++;
			res=max(res,curr);
		}
	}
	return res;
}
//Naive way
//logic:if 0 comes then we break the loop,again calculate the consecutive ones and compare it with previous result
int maxconsecutiveones(int arr[],int n)
{
	int res=0,curr;
	for(int i=0;i<n;i++)
	{
		curr=0;
		for(int j=i;j<n;j++)
		{
			if(arr[j]==1)
			{
				curr++;
				res=max(res,curr);
			}
			else
			{
				break;
			}
		}
	}
	return res;
}
int main()
{
	int arr[]={0,1,1,0,1,1,1};
	cout<<"Maximum consecutive ones :"<<maxconsecutiveones(arr,7);
}
