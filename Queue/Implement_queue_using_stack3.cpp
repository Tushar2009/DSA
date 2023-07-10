#include<bits/stdc++.h>
using namespace std;
class Queue
{
    stack<int> st;
    public:
    void enqueue(int x)
    {
        st.push(x);
    }
    //using  stack 1 only 
    int dequeue()
    {

        if(st.empty())return -1;

        int x=st.top();
        st.pop();
        if(st.empty())
        {
            return x;
        }
        int item=dequeue();
        st.push(x);
        return item;
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