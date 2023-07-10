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
    int extractMin()
    {
        if(size==0)return INT_MAX;
        if(size==1)
        {
            size--;
            return arr[0];
        }
        swap(arr[0],arr[size-1]);
        size--;
        minHeapify(0);
        return arr[size];
    }
    //Time complexity is O(log(size)) 
    void decrease_key(int i,int x)
    {
        arr[i]=x;
        while(i!=0 && arr[parent(i)]>arr[i])
        {
            swap(arr[parent(i)],arr[i]);
            i=parent(i);
        }
    }
    //Time complexity is O(log(size)) 
    void deletekey(int i)
    {
        decrease_key(i,INT_MIN);
        extractMin();

    }

};
int main() 
{ 
    MinHeap h(11);
    h.insert(3); 
    h.insert(2);
    h.deletekey(0);
    h.insert(15);
    h.insert(20);
    cout << h.extractMin() << endl;
    h.decrease_key(2, 1);
    cout << h.extractMin() << endl;
    return 0;
}