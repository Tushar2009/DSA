#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;
    Node(int value)
    {
        val = value;
        next = NULL;
        random = NULL;
    }
};
// brute force using extra space
Node *copyRandomList(Node *head)
{
    unordered_map<Node *, Node *> hashMap;
    Node *temp = head;
    // first iteration for inserting deep nodes of every node in the hashmap.
    while (temp != NULL)
    {
        Node *newNode = new Node(temp->val);
        hashMap[temp] = newNode;
        temp = temp->next;
    }
    Node *t = head;
    // second iteration for linking next and random pointer as given question.
    while (t != NULL)
    {
        Node *node = hashMap[t];
        node->next = (t->next != NULL) ? hashMap[t->next] : NULL;
        node->random = (t->random != NULL) ? hashMap[t->random] : NULL;
        t = t->next;
    }
    return hashMap[head];
}
template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode<T> *random;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};
// optimal solution
// Time Complexity :O(n)
// space Complexity :O(1)
LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    LinkedListNode<int> *iter = head;
    LinkedListNode<int> *front = head;
    while (iter != NULL)
    {
        front = iter->next;
        LinkedListNode<int> *copy = new LinkedListNode<int>(iter->data);
        iter->next = copy;
        copy->next = front;
        iter = front;
    }
    iter = head;
    while (iter != NULL)
    {
        if (iter->random != NULL)
            iter->next->random = iter->random->next;
        else
            iter->next->random = NULL;
        iter = iter->next->next;
    }
    iter = head;
    front = head;
    LinkedListNode<int> *dummy = new LinkedListNode<int>(0);
    LinkedListNode<int> *temp = dummy;
    while (iter != NULL)
    {
        front = iter->next->next;
        temp->next = iter->next;
        iter->next = front;
        temp = temp->next;
        iter = front;
    }
    return dummy->next;
}