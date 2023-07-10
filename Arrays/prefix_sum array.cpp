#include<iostream>
using namespace std;
int prefix_sum[1000];
void presum(int arr[],int n)
{
	prefix_sum[0]=arr[0];
	for(int i=1;i<n;i++)
	{
		prefix_sum[i]=prefix_sum[i-1]+arr[i];
	}
}
int getsum(int prefix_sum[],int l,int r)
{
	if(l!=0)
	{
		return prefix_sum[r]-prefix_sum[l-1];
	}
	else
	{
		return prefix_sum[r];
	}
}
int main() {
	
      int arr[] = {2, 8, 3, 9, 6, 5, 4}, n = 7;

      presum(arr, n);

     cout<<getsum(prefix_sum, 1, 3)<<endl;
     
     cout<<getsum(prefix_sum, 0, 2)<<endl;
    
}
