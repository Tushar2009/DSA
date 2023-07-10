#include<iostream>
using namespace std;
//efficient way
//logic: Is that ki agar element majority mai hai then uska count 0 ho hi ni payega 
//agar vo half of array sa jada baar present hai
int findMajority(int arr[], int n)
{
	//finding the majority element
	int res = 0, count = 1;

    	for(int i = 1; i < n; i++)
    	{
    		if(arr[res] == arr[i])
    			count++;
    		else 
    			count --;

    		if(count == 0)
    		{
    			res = i; count = 1;
    		}
    	}
  // check if candidate is actually a majority
    	count = 0;

    	for(int i = 0; i < n; i++)
    		if(arr[res] == arr[i])
    			count++;

    	if(count <= n /2)
    		res = -1;

    	return res; 
}
int majority(int arr[],int n)
{
	for(int i=0;i<n;i++)
	{
		int count=1;
		for(int j=i+1;j<n;j++)
		{
			if(arr[i]==arr[j])
			{
				count++;
			}
		}
		if(count>n/2)
		return i;
	}
	return -1;
}
int main()
{
	int arr[]={6,8,4,8,8};
	cout<<"Majority element is present at index :"<<findMajority(arr,5)<<endl;
}
