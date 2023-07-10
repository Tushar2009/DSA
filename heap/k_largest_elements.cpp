//method 1
// #include<bits/stdc++.h>
// using namespace std;
// //Time complexity is O(n+klog(n))
// int main()
// {
//     int arr[]={5,15,10,20,8};
//     int k=2;
//     priority_queue <int> pq;
//     for(int i=0;i<5;i++)
//     {
//         pq.push(arr[i]);
//     }
//     while(pq.empty()==false)
//     {
//         if(k>0)
//         {
//         cout<<pq.top()<<" ";
//         pq.pop();
//         }
//         else
//         {
//             break;
//         }
//         k--;
//     }
//     return 0;
// }

//method 2
#include<bits/stdc++.h>
using namespace std;
void firstKElements(int arr[],int n,int k)
{
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<k;i++) {
        pq.push(arr[i]);
    }
    //Here logic is that if top element is less than the current element then it should be removed from
    //queue the greater current element should be added
    for(int i=k;i<n;i++)
    {
        if(pq.top()>arr[i])
        {
            continue;
        }
        else
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    while(!pq.empty())
    {
        cout<<pq.top()<<" ";
        pq.pop();
    }
}
int main()
{

	int arr[] = { 11, 3, 2, 1, 15, 5, 4, 45, 88, 96, 50, 45 };

	int size = sizeof(arr) / sizeof(arr[0]);

	int k = 3;

	firstKElements(arr,size,k);

	return 0;
}