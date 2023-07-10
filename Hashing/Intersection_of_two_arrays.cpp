#include<bits/stdc++.h>
using namespace std;
// naive solution
// Time complexity is O(m*(m+n))
// aux space is O(1)
int intersection(int a[],int b[],int m,int n)
{
    int res=0;
    for(int i=0;i<m;i++)
    {
        bool flag=false;
        //this loop checks element is already being used or not
        for(int j=0;j<i;j++) 
        {
            if(a[i]==a[j])
            {
                flag=true;
                break;
            }
        }
        if(flag==true)
        {
            continue;
        }
        for(int j=0;j<n;j++)
        {
            if(a[i]==b[j])
            {
                res++;
                break;
            }
        }
    }
    return res;
}
int intersection_2(int a[],int b[],int m,int n)
{
    int res=0;
    unordered_set<int> s;
    for(int i=0;i<m;i++)
    {
        s.insert(a[i]);
    }
    for(int i=0;i<n;i++)
    {
        if(s.find(b[i])!=s.end())
        {
            res++;
            s.erase(b[i]);
        }
    }
    return res;
}
int main()
{
    int a[]={10,10,30,20};
    int b[]={20,10,40,10,40};
    cout<<"Intersection of two arrays is :"<<intersection_2(a,b,4,5)<<endl;
    return 0;
}