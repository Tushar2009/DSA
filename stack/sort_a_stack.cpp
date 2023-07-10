#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}
void insert(stack<int>& s,int data)
{
    if(s.empty())
    {
        s.push(data);
        return;
    }
    if(data>=s.top())
    {
        s.push(data);
        return;
    }
    int temp=s.top();
    s.pop();
    insert(s,data);
    s.push(temp);
}
void SortedStack :: sort()
{
   //Your code here
   if(s.empty())return;
   int data=s.top();
   s.pop();
   sort();
   insert(s,data);
   
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}