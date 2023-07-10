#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Queue
{
    int size;
    int cap;
    int *arr;
    int front;
    public:
    Queue(int cap)
    {
        this->front=0;
        this->size = 0;
        this->cap = cap;
        arr=new int[cap];
    }
    bool isEmpty()
    {
        if(size==0)
        {
            return true;
        }
        return false;
    }
    bool isfull()
    {
        if(size==cap)
        {
            return true;
        }
        return false;
    }
    int Dequeue()
    {
        if(isEmpty())return -1;
        int x=arr[front];
        front=(front+1)%cap;
        size--;
        return x;
    }
    // return front index
    int getfront()
    {
        if(isEmpty())return -1;
        return front;
    }
    //returns the index of rear from circular array
    int getRear()
    {
        if(isEmpty())return -1;
        return (front+size-1)%cap;
    }
    void Enqueue(int x)
    {
        if(isfull())return;
        int rear=getRear();
        rear=(rear+1)%cap;
        arr[rear]=x;
        size++; 
    }
};
int main()
{
    Queue q(1000);
    q.Enqueue(10); 
	q.Enqueue(20); 
	q.Enqueue(30); 
	q.Enqueue(40); 

	cout<<q.Dequeue()<< " dequeued from queue"<<endl; 

	cout << "Front index is :"<< q.getfront() << endl; 
	cout << "Rear index is :"<< q.getRear() << endl; 
	return 0;
}
