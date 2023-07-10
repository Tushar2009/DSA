#include<bits/stdc++.h>
#include<iostream>
#include<queue>
using namespace std;
void print(queue<int> queue)
{
    while(!queue.empty())
    {
        cout<<queue.front()<<" ";
        queue.pop();
    }
}
//using stack
void reverse_Queue(queue<int> &q)
{
    stack<int> st;
    while(!q.empty())
    {
        st.push(q.front());
        q.pop();
    }
    while(!st.empty())
    {
        q.push(st.top());
        st.pop();
    }
}
//using recursive method
void recursive_reverse(queue<int> &q)
{
    if(q.empty())return;
    int x=q.front();
    q.pop();
    recursive_reverse(q);
    q.push(x);
}
int main() 
{ 
	queue<int> q; 
	q.push(12); 
	q.push(5); 
	q.push(15);
	q.push(20); 
    print(q);
    cout<<endl;
	recursive_reverse(q); 
	print(q); 
}