#include<iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node (int d)
    {
       data=d;
       next=NULL;
    }
};
class mystack
{
    Node *Head;
    int sz;
    public:
    mystack()
    {
        Head=NULL;
        sz=0;
    }
    void push(int d)
    {
        Node *temp=new Node(d);
        temp->next=Head;
        Head=temp;
        sz++;
    }
    int  pop()
    {
        if(Head==NULL) return INT_MAX;
        int res=Head->data;
        Node *temp=Head;
        Head=Head->next;
        delete temp;
        sz--;
        return res;
    }
    int size()
    {
        return sz;
    }
    bool isEmpty()
    {
        if(Head==NULL) return true;
        return false;
    }
    int peek()
    {
        if(Head==NULL) return INT_MAX;
        return Head->data;
    }
};
int main()
{
   mystack s;
   s.push(5);
   s.push(10);
   s.push(20);
   cout<<s.pop()<<endl;
   cout<<s.size()<<endl;
   cout<<s.peek()<<endl;
   cout<<s.isEmpty()<<endl;
   return 0;
}
