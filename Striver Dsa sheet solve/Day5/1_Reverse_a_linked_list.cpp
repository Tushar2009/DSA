#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
};
// Time Complexity :O(n)
// space Complexity :O(1)
struct Node *reverseList(struct Node *head)
{
    // code here
    // return head of reversed list
    Node *prev = NULL;
    Node *current = head;
    Node *next;
    while (current)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}