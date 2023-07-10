#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
	int temp;
	temp=*a;
	*a=*b;
	*b=temp;
}
// efficient way in O(n) time 
void move_zeros(int arr[],int n)
{
	int count=0;
	for(int i=0;i<n;i++)
	{
		if(arr[i]!=0)
		{
			swap(&arr[i],&arr[count]);
			count++;
		}
	}
}
/*void move_zeros(int arr[],int n)
{
	int temp,i,j;
	for(i=0;i<n;i++)
	{
		if(arr[i]==0)
		{
		  for(j=i+1;j<n;j++)
		  {
		  	if(arr[j]!=0)
		  	{
		       swap(&arr[i],&arr[j]);
		       break;
			}
		  	
		  }	
		}
	}
} */
int main()
{
	int arr[]={10,5,0,0,8,0,9,0};
	move_zeros(arr,8);
	cout<<"Moving Zeros to end of array :"<<endl;
	for(int i=0;i<8;i++)
	{
		cout<<arr[i]<<" ";
	}
	
}
