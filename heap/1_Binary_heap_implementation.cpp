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

};
int main() 
{ 
    MinHeap h(11);
    return 0;
} 
