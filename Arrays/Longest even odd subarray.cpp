#include<iostream>
using namespace std;
//efficient way 
//logic:in we we will count the current until the elements will be alternatively odd or even 
//else we will set current=1 and again find the new greater combination of even and odd 
int longest_eve_odd_sub_array(int arr[],int n)
{
	int res=1;
	int curr=1;
	for(int i=1;i<n;i++)
	{
		if((arr[i]%2==0 && arr[i-1]%2!=0)|| (arr[i]%2!=0 && arr[i-1]%2==0))
		{
			curr++;
			res=max(res,curr);
		}
		else
		{
			curr=1;
		}
	}
	return res;
}
int longest_eve_odd_sub_array2(int arr[],int n)
{
	int res=1;
	for(int i=0;i<n;i++)
	{
		int curr=1;
		for(int j=i+1;j<n;j++)
		{
			if((arr[j]%2==0 && arr[j-1]%2!=0)|| (arr[j]%2!=0 && arr[j-1]%2==0))
		    {
			   curr++;
		    }
		    else
		    {
			  break;
		    }
		}
		res=max(res,curr);
	}
	return res;
}
int main()
{
	int arr[]={5,10,20,6,3,8};
	cout<<"longest even-odd subarray :"<<longest_eve_odd_sub_array(arr,6)<<endl;
	return 0;
}
