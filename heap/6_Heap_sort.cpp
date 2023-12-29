#include <bits/stdc++.h>
using namespace std;

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
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

int main()
{
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, n);

    cout << "Sorted array is \n";
    printArray(arr, n);
}