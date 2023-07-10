#include<bits/stdc++.h>
using namespace std;
class Queue
{
    stack<int> st1,st2;
    int curr_size;
    public:
    Queue()
    {
        curr_size = 0;
    }
    void enqueue(int x)
    {
       while(!st1.empty())
       {
         st2.push(st1.top());
         st1.pop();
       }
       st1.push(x);
       while(!st2.empty())
       {
         st1.push(st2.top());
         st2.pop();
       }
       curr_size++;
    }
    void dequeue()
    {
        if(st1.empty())return;
        st1.pop();
        curr_size--;
    } 
    int  queueFront()
    {
        return st1.top();
    }
    int queueRear()
    {
        int s=curr_size;
        while(s!=0)
        {
            st2.push(st1.top());
            st1.pop();
            s--;
        }
        int x=st2.top();
        stack<int> st=st1;
        st1=st2;
        st2=st;
        return x;

    }
    int size()
    {
        return curr_size;
    }
};
int main()
{
    Queue q; 
	q.enqueue(10); 
	q.enqueue(5); 
	q.enqueue(15); 
	q.enqueue(20);

	cout << "current size: " << q.size() << endl; 
	cout << q.queueFront() << endl; 
	q.dequeue(); 
	cout << q.queueFront() << endl; 
	q.enqueue(80); 
	cout << q.queueRear() << endl; 
	cout << "current size: " <<  q.size() << endl; 
	return 0; 
}