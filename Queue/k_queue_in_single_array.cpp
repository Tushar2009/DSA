#include<bits/stdc++.h>
using namespace std;
class kQueues
{
    int *arr,*next,*front,*rear,cap,k,free;
    public:
    kQueues(int c,int k1)
    {
        cap=c;
        k=k1;
        arr=new int[cap];
        next=new int[cap];
        front=new int[k];
        rear=new int[k];
        for(int i=0;i<k;i++)
        {
            front[i]=-1;
            rear[i]=-1;
        }
        free=0;
        for(int i=0;i<cap-1;i++)
        {
            next[i]=i+1;
        }
        next[cap-1]=-1;
    }
    bool isFull()
    {
        if(free==-1)return true;
        return false;
    }
    bool isEmpty(int qn)
    {
        if(front[qn]==-1)return true;
        return false;
    }
    void enqueue(int x,int qn)
    {
        if(isFull())return;
        int i=free;
        free=next[i];
        if(isEmpty(qn))
        {
          front[qn]=i;
        }
        else
        {
            next[rear[qn]]=i;
        }
        next[i]=-1;
        rear[qn]=i;
        arr[i]=x;
    }
    int dequeue(int qn)
    {
        if(isEmpty(qn))return INT_MAX;
        int i=front[qn];
        front[qn]=next[i];
        next[i]=free;
        free=i;
        return arr[i];
    }
};
int main()
{
    // Let us create 3 queue in an array of size 10
    int k = 3, n = 10;
    kQueues ks(n, k);
 
    // Let us put some items in queue number 2
    ks.enqueue(15, 2);
    ks.enqueue(45, 2);
 
    // Let us put some items in queue number 1
    ks.enqueue(17, 1);
    ks.enqueue(49, 1);
    ks.enqueue(39, 1);
 
    // Let us put some items in queue number 0
    ks.enqueue(11, 0);
    ks.enqueue(9, 0);
    ks.enqueue(7, 0);
 
    cout << "Dequeued element from queue 2 is " << ks.dequeue(2) << endl;
    cout << "Dequeued element from queue 1 is " << ks.dequeue(1) << endl;
    cout << "Dequeued element from queue 0 is " << ks.dequeue(0) << endl;
 
    return 0;
}