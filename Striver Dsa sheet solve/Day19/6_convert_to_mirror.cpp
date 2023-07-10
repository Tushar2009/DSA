#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
void mirror(Node *node)
{
    // code here
    if (node != NULL)
    {
        swap(node->left, node->right);
        mirror(node->left);
        mirror(node->right);
    }
}