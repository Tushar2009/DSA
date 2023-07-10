#include<bits/stdc++.h>
using namespace std;
class Queue
{
    stack<int> st1,st2;
    public:
    void enqueue(int x)
    {
        st1.push(x);
    }
    int dequeue()
    {
        while(!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        int x=st2.top();
        st2.pop();
        while(!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }
        return x;
    } 
};
int main()
{
    Queue q; 
	q.enqueue(10); 
	q.enqueue(5); 
	q.enqueue(15); 
	q.enqueue(20);

	cout << q.dequeue() << endl; 
	cout << q.dequeue() << endl; 
	q.enqueue(80); 
	cout << q.dequeue() << endl; 
	return 0; 
}