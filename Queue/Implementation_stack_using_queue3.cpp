#include<bits/stdc++.h>
#include<queue>
using namespace std;
class Stack
{
    queue<int> q;
    int curr_size;
    public:
    Stack()
    {
        curr_size = 0;
    }
    //using 1 queue only
    void push(int x)
    {
        q.push(x);
        for(int i=0;i<curr_size;i++)
        {
            q.push(q.front());
            q.pop();
        }
        curr_size++;
    }
    void pop()
    {
        if(q.empty())return;
        q.pop();
        curr_size--;
    }
    int top()
    {
        if(q.empty())return -1;
        return q.front();
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
	s.pop(); 
	cout << s.top() << endl; 
	s.pop(); 
	cout << s.top() << endl; 

	cout << "current size: " <<  s.size() << endl; 
	return 0; 
}