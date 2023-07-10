#include <bits/stdc++.h>
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
        size = 0;
        arr = new int[capacity];
    }
    int left(int i)
    {
        return (2 * i + 1);
    }
    int right(int i)
    {
        return (2 * i + 2);
    }
    int parent(int i)
    {
        return (i - 1) / 2;
    }
    // Time complexity is O(log(size))
    void insert(int x)
    {
        if (size == capacity)
            return;
        size++;
        arr[size - 1] = x;
        for (int i = size - 1; i != 0 && arr[parent(i)] > arr[i];)
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }
    // Recursive way
    // Time complexity is O(log(size))
    // aux space is O(log(size))
    void minHeapify(int i)
    {
        int smallest = i;
        int lt = left(i), rt = right(i);
        if (lt < size && arr[lt] < arr[i])
        {
            smallest = lt;
        }
        if (rt < size && arr[rt] < arr[i])
        {
            smallest = rt;
        }
        if (smallest != i)
        {
            swap(arr[i], arr[smallest]);
            minHeapify(smallest);
        }
    }
    int extractMin()
    {
        if (size == 0)
            return INT_MAX;
        if (size == 1)
        {
            size--;
            return arr[0];
        }
        swap(arr[0], arr[size - 1]);
        size--;
        // minHeapify(0);
        minHeapify(0);
        return arr[size];
    }
    // Time complexity is O(log(size))
    void decrease_key(int i, int x)
    {
        arr[i] = x;
        while (i != 0 && arr[parent(i)] > arr[i])
        {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }
    // Time complexity is O(log(size))
    void deletekey(int i)
    {
        decrease_key(i, INT_MIN);
        extractMin();
    }
    // Time complexity is O(log(size))
    void build_heap()
    {
        // Starting from inner right_most node means parent of last node
        for (int i = (size - 2) / 2; i >= 0; i--)
        {
            minHeapify(i);
        }
    }
    void maxheapify(int arr[], int n, int i)
    {
        int largest = i;
        int lt = 2 * i + 1, rt = 2 * i + 2;
        if (lt < n && arr[lt] > arr[largest])
        {
            largest = lt;
        }
        if (rt < n && arr[rt] > arr[largest])
        {
            largest = rt;
        }
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            maxheapify(arr, n, largest);
        }
    }
    void buildheap(int arr[], int n)
    {
        // here we start from parent of last node
        for (int i = n / 2 - 1; i >= 0; i--)
            maxheapify(arr, n, i);
    }
    void heapSort(int arr[], int n)
    { // step 1: Build a Max heap;
        buildheap(arr, n);
        // step 2: Repeatedly swap the root with last node,reduce heap size by 1 and heapify
        for (int i = n - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]);
            maxheapify(arr, i, 0);
        }
    }
};