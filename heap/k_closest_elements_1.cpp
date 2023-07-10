#include<bits/stdc++.h>
using namespace std;
//k=no. of elements
//x=element whose closest elements we want
// Time complexity is O(nk)
// Aux space is O(n)
void printKClosest(int arr[], int n, int k, int x)
{
    bool visited[n]={false};
    for(int i=0;i<k;i++)
    {
        int Min_diff=INT_MAX;
        int MIN_diff_index;
        for(int j=0;j<n;j++)
        {
            if(visited[j]==false && abs(arr[j]-x)<=Min_diff)
            {
                Min_diff=abs(arr[j]-x);
                MIN_diff_index=j;
            }
        }
        cout<<arr[MIN_diff_index]<<" ";
        visited[MIN_diff_index]=true;
    }

}
int main()
{

	int arr[] = { 10,30,5,40,38,80,70 };

	int size = sizeof(arr) / sizeof(arr[0]);

	int x=35; int k = 3;

	printKClosest(arr,size,k,x);

	return 0;
}
