#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    Node *left;
    Node *right;
    Node(int x)
    {
        key = x;
        right = left = NULL;
    }
};
// Time complexity is O(n)
//  Aux space is O(h) (h=height of binary tree)
Node *temp = new Node(-1);
Node *res = temp;
Node *convert_tree_to_DLL(Node *root)
{
    if (root == NULL)
        return root;
    if (root != NULL)
    {
        convert_tree_to_DLL(root->left);
        temp->right = root;
        root->left = temp;
        temp = root;
        convert_tree_to_DLL(root->right);
    }
    return res->right;
}