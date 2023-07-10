#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
Node *merge(Node *a, Node *b)
{
    Node *temp = new Node(0);
    Node *res = temp;
    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else
        {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    while (a != NULL)
    {
        temp->bottom = a;
        temp = temp->bottom;
        a = a->bottom;
    }
    while (b != NULL)
    {
        temp->bottom = b;
        temp = temp->bottom;
        b = b->bottom;
    }
    return res->bottom;
}
Node *flatten(Node *root)
{
    // Your code here
    if (root == NULL || root->next == NULL)
    {
        return root;
    }
    // to reach the last 2 nodes first
    root->next = flatten(root->next);
    root = merge(root, root->next);
    return root;
}