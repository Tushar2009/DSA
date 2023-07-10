#include<iostream>
using namespace std;
int search(int arr[],int n,int x)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i]==x)
        {
            return i; 
        }
    }
    return -1;
}
int main()
{
    int arr[]={1,2,3,4,5,6,7};
    int x;
    cout<<"Enter the element to be searched :"<<endl;
    cin>>x;
    int result=search(arr,7,x);
    cout<<"The element "<<x<<" is present at index "<<result<<endl;

}
