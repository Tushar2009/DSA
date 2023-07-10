#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        key = x;
        left = NULL;
        right = NULL;
    }
};
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    // Your code goes here
    Node *cur = root;
    while (cur != NULL)
    {
        if (cur->key <= key)
        {
            cur = cur->right;
        }
        else
        {
            suc = cur;
            cur = cur->left;
        }
    }
    cur = root;
    while (cur != NULL)
    {
        if (cur->key >= key)
        {
            cur = cur->left;
        }
        else
        {
            pre = cur;
            cur = cur->right;
        }
    }
}