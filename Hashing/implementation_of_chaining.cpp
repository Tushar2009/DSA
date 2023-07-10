#include <bits/stdc++.h>
using namespace std;
// Normally, when we say a List, we talk about a doubly linked list.
struct MyHash
{
    int bucket;
    list<int> *table;
    MyHash(int b)
    {
        bucket = b;
        table = new list<int>[bucket];
    }
    void insert(int key)
    {
        int i = key % bucket;
        table[i].push_back(key);
    }
    bool search(int key)
    {
        int i = key % bucket;
        for (auto x : table[i])
        {
            if (x == key)
                return true;
        }
        return false;
    }
    void remove(int key)
    {
        int i = key % bucket;
        table[i].remove(key);
    }
};
int main()
{
    MyHash mh(7);
    mh.insert(10);
    mh.insert(20);
    mh.insert(15);
    mh.insert(7);
    cout << mh.search(10) << endl;
    mh.remove(15);
    cout << mh.search(15);
}