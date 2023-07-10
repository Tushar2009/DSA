#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *right;
    Node *left;
    Node(int x)
    {
        key = x;
        left = right = NULL;
    }
};

// Recursive
bool search1(Node *root, int x)
{
    if (root == NULL)
        return false;
    if (root->key == x)
        return true;
    else if (root->key > x)
    {
        return search1(root->left, x);
    }
    else
    {
        return search1(root->right, x);
    }
}

// Iterative
bool search2(Node *root, int x)
{
    while (root != NULL)
    {
        if (root->key == x)
            return true;
        if (root->key > x)
        {
            root = root->left;
        }
        else if (root->key < x)
        {
            root = root->right;
        }
    }
    return false;
}