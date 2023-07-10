#include<bits/stdc++.h>
using namespace std;
class MinHeap
{
    int *arr;
    int size;
    int capacity;
    public:
    MinHeap(int cap)
    {
        capacity = cap;
        size=0;
        arr=new int[capacity];
    }
    int left(int i) 
    { 
        return (2*i + 1); 
    } 
    int right(int i) 
    { 
        return (2*i + 2); 
    } 
    int parent(int i)  
    { 
        return (i-1)/2; 
    }
    //Time complexity is O(log(size))
    void insert(int x)
    {
        if(size==capacity)return;
        size++;
        arr[size-1]=x;
        for(int i=size-1;i!=0 && arr[parent(i)]>arr[i];)
        {
            swap(arr[parent(i)],arr[i]);
            i=parent(i);
        }
    }
    void minHeapify(int i)
    {
        int smallest=i;
        int lt=left(i),rt=right(i);
        if(lt<size && arr[lt]<arr[i])
        {
            smallest=lt;
        }
        if(rt<size && arr[rt]<arr[i])
        {
            smallest=rt;
        }
        if(smallest!=i)
        {
            swap(arr[i],arr[smallest]);
            minHeapify(smallest);
        }
    }
    //Time complexity is O(log(size))
    void build_heap()
    {
        //Starting from inner right_most node means parent of last node
        for(int i=(size-2)/2;i>=0;i--)
        {
            minHeapify(i);
        }
    } 

};
int main() 
{ 
    MinHeap h(11);
    return 0;
}