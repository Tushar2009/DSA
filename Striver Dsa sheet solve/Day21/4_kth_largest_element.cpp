#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};
class Solution
{
public:
    int cnt = 0;
    int ans = 0;
    void inorder(Node *root, int k)
    {
        if (root == NULL)
            return;
        inorder(root->right, k);
        cnt++;
        if (cnt == k)
        {
            ans = root->data;
            return;
        }
        inorder(root->left, k);
    }
    int kthLargest(Node *root, int K)
    {
        // Your code here
        inorder(root, K);
        return ans;
    }
};