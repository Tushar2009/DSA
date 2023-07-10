#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class dequeue
{
    int size,cap,front;
    int *arr;
    public:
    dequeue(int c)
    {
        cap=c;
        front=0;
        size=0;
        arr=new int[cap];
    }
    bool isFull()
    {
        if(size==cap)return true;
        return false;
    }
    bool isEmpty()
    {
        if(size==0)return true;
        return false;
    }
    void deleteFront()
    {
        if(isEmpty())return;
        front=(front+1)%cap;
        size--;
    }
    void insertRear(int x)
    {
        int rear=getRear();
        rear=(rear+1)%cap;
        arr[rear]=x;
        size++;
    }
    int getRear()
    {
        if(isEmpty())return -1;
        return (front+size-1)%cap;
    }
    void deleteRear()
    {
        if(isEmpty())return;
        size--;
    }
    void insertFront(int x)
    {
        if(isFull())return;
        front=(front-1+cap)%cap;
        arr[front]=x;
        size++;
    }
    int getFront()
    {
        if(isEmpty())return -1;
        else
        {
            return front;
        }
    }
};
int main()
{
    dequeue d(5);
    d.insertRear(10);
    d.insertFront(20);
    d.insertFront(30);
    cout<<d.getFront()<<endl;
    cout<<d.getRear()<<endl;
    return 0;
}