//frequencies in an sorted array
#include<iostream>
using namespace std;
void freq(int arr[],int n)
{
   int freq=1,i=1;
   while(i<n)
   {
   	  while(i<n && arr[i-1]==arr[i])
   	  {
   	  	freq++;
   	  	i++;
	  }
	  cout<<arr[i-1]<<" :"<<freq<<endl;
	  i++;
	  freq=1;
   }
   if(n==1 || arr[n-2]!=arr[n-1])
   {
   	  cout<<arr[n-1]<<" :"<<1<<endl;
   }
} 
int main()
{
	int arr[]={10,10,10,20,20,30};
	freq(arr,6);
	
}
