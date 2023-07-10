#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Dequeue
{
    int cap,size;
    int *arr;
    public:
    Dequeue(int c)
    {
        cap=c;
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
    void insertRear(int x)
    {
        if(isFull())return;
        arr[size]=x;
        size++;
    }
    void deleteRear()
    {
        if(isEmpty())return;
        size--;
    }
    int getRear()
    {
        if(isEmpty())return -1;
        return arr[size-1];
    }
    void insertFront(int x)
    {
        if(isFull())return;
        for(int i=size-1;i>=0;i--)
        {
            arr[i+1]=arr[i];
        }
        arr[0]=x;
        size++;
    }
    void deleteFront()
    {
        if(isEmpty())return;
        for(int i=0;i<size-1;i++)
        {
            arr[i]=arr[i+1];
        }
        size--;
    }
    int getFront()
    {
        if(isEmpty())return -1;
        return arr[0];
    }
};
int main()
{
    Dequeue d(5);
    d.insertRear(10);
    d.insertFront(20);
    cout<<d.getFront()<<endl;
    cout<<d.getRear()<<endl;
    return 0;
}