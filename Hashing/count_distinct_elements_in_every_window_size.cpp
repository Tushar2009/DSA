#include<bits/stdc++.h>
using namespace std;
//naive way
void printDistinct(int arr[], int n, int k)
{
    // loop works for every window
    for(int i=0;i<=n-k;i++){
        int count=0;
        for(int j=0;j<k;j++){
            bool flag=false;
            //this loop checks whether the element has already being counted or not
            for(int p=0;p<j;p++){
                if(arr[i+j]==arr[i+p])
                {
                    flag=true;break;
                }
            }
            if(flag==false)count++;
            
        }
        cout<<count<<" ";
    }
}
//efficient way
//Time complexity is O(n)
//Aux space is O(k)
void print_distinct(int arr[],int n,int k)
{
    unordered_map<int,int> m;
    for(int i=0;i<k;i++)
    {
        m[arr[i]]++;
    }
    cout << m.size() <<" ";
    for(int i=k;i<n;i++)
    {
        m[arr[i-k]]--;
        if(m[arr[i-k]]==0)
        {
            m.erase(arr[i-k]);
        }
        if(m.find(arr[i])!=m.end())
        {
            m[arr[i]]++;
        }
        if(m.find(arr[i])==m.end())
        {
            m[arr[i]]++;
        }
        cout<<m.size()<<" ";
    }
}
int main()
{
    int arr[]={10,10,5,3,20,5};
    int k=4;
    int n=sizeof(arr)/sizeof(arr[0]);
    print_distinct(arr,n,k);
}