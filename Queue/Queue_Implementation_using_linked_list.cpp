#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data=x;
        next=NULL;
    }
};
class Queue
{
    Node *rear,*front;
    int size;
    public:
    Queue()
    {
        rear=front=NULL;
        size=0;
    }
    void enqueue(int x)
    {
        Node *temp=new Node(x);
        if(rear==NULL)
        {
            front=rear=temp;
            size++;
            return;
        }
        rear->next=temp;
        rear=temp;
    }
    void dequeue()
    {
        if(front==NULL) return;
        Node *temp=front;
        front=front->next;
        if(front==NULL)
        {
            rear=NULL;
        }
        delete (temp);
    } 
    int  queueFront()
    {
        if(front==NULL) return 0;
        return front->data;
    }
    int queueRear()
    {
       if(rear==NULL) return 0;
       return rear->data;
    }
};
int main()
{
    Queue q; 
	q.enqueue(10); 
	q.enqueue(20); 
	q.dequeue(); 
	q.dequeue(); 
	q.enqueue(30); 
	q.enqueue(40); 
	q.enqueue(50); 
	q.dequeue(); 
	cout << "Queue Front : " <<q.queueFront()<< endl; 
	cout << "Queue Rear : " <<q.queueRear(); 
    return 0;
}