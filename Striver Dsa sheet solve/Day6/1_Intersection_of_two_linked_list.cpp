#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};
int countdiff(Node *a, Node *b)
{
    int c1 = 0, c2 = 0;
    while (a != NULL)
    {
        c1++;
        a = a->next;
    }
    while (b != NULL)
    {
        c2++;
        b = b->next;
    }
    return c1 - c2;
}
// optimal solution 1
// Time Complexity: O(2max(length of list1,length of list2))+O(abs(length of list1-length of list2))+O(min(length of list1,length of list2))
// space complexity :O(1)
Node *findIntersection(Node *firstHead, Node *secondHead)
{
    // Write your code here
    int diff = countdiff(firstHead, secondHead);
    if (diff < 0)
    {
        while (diff++ != 0)
            secondHead = secondHead->next;
    }
    else
    {
        while (diff-- != 0)
            firstHead = firstHead->next;
    }
    while (firstHead != NULL)
    {
        if (firstHead == secondHead)
            return firstHead;
        firstHead = firstHead->next;
        secondHead = secondHead->next;
    }
    return NULL;
}
// optimal solution 2
// Time Complexity: O(2*max(length of list1,length of list2))
// Space Complexity: O(1)
Node *findIntersection(Node *firstHead, Node *secondHead)
{
    // Write your code here
    if (firstHead == NULL || secondHead == NULL)
        return NULL;
    Node *d1 = firstHead, *d2 = secondHead;
    while (d1 != d2)
    {
        d1 = d1 == NULL ? secondHead : d1->next;
        d2 = d2 == NULL ? firstHead : d2->next;
    }
    return d1;
}