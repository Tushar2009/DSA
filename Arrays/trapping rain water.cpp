#include<iostream>
#include<cmath>
using namespace std;
// logic=isma hm har ek element ka leftmax and rightmax find karka phir minus us particular block ki height
//efficient way
int getwater(int arr[],int n)
{
	int res=0;
	int lmax[n],rmax[n];
	lmax[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		lmax[i]=max(arr[i],lmax[i-1]);
	}
	rmax[n-1]=arr[n-1];
	for(int j=n-2;j>=0;j--)
	{
		rmax[j]=max(arr[j],rmax[j+1]);
	}
	for(int i=1;i<n-1;i++)
	{
		res=res+min(lmax[i],rmax[i])-arr[i];
	}
	return res;
}
int main()
{
	int arr[]={5,0,6,2,3};
	int result=getwater(arr,5);
	cout<<"The amount of water we can store is :"<<result<<endl;
}
