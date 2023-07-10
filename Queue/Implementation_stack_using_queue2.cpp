#include<bits/stdc++.h>
#include<queue>
using namespace std;
class Stack
{
    queue<int> q1,q2;
    int curr_size;
    public:
    Stack()
    {
        curr_size = 0;
    }
    void push(int x)
    {
        curr_size++;
        q1.push(x);
    }
    void Pop()
    {
        if(q1.empty())return;
        while(q1.size()!=1)
        {
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        queue<int> q=q1;
        q1=q2;
        q2=q;
        curr_size--;
    }
    int top()
    {
        if(q1.empty())return -1;
        return q1.back();
    }
    int size()
    {
        return curr_size;
    }
};
int main()
{
    Stack s; 
	s.push(10); 
	s.push(5); 
	s.push(15); 
	s.push(20);

	cout << "current size: " << s.size() << endl; 
	cout << s.top() << endl; 
	s.Pop(); 
	cout << s.top() << endl; 
	s.Pop(); 
	cout << s.top() << endl; 

	cout << "current size: " <<  s.size() << endl; 
	return 0; 
}