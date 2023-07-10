#include<iostream>
#include<cmath>
using namespace std;
// logic=isma hm har ek element ka leftmax and rightmax find karka phir minus us particular block ki height
int getwater(int arr[],int n)
{
	int res=0;
	int lmax,rmax;
	//we start the loop one after and one before the limit because the ending of blocks do not store any water
	for(int i=1;i<n-1;i++)
	{
		lmax=arr[i];
		//finding the leftmax for every particular element
		for(int j=0;j<i;j++)
		{
			lmax=max(lmax,arr[j]);
		}
		rmax=arr[i];
		//finding the rightmax for every particular element
		for(int j=i+1;j<n;j++)
		{
			rmax=max(rmax,arr[j]);
		}
		res=res+min(lmax,rmax)-arr[i];
	}
	return res;
}
int main()
{
	//In this array basically the heights of blocks are given
	int arr[]={5,0,6,2,3};
	int result=getwater(arr,5);
	cout<<"The amount of water we can store is :"<<result<<endl;
}
