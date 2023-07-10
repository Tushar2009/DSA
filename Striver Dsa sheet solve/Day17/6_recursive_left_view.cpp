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
// Time Complexity: O(N)

// Space Complexity: O(H)       (H -> Height of the Tree)
void left(Node *root, int level, vector<int> &ds)
{
    if (root == NULL)
        return;
    if (level == ds.size())
        ds.push_back(root->data);
    left(root->left, level + 1, ds);
    left(root->right, level + 1, ds);
}
vector<int> leftView(Node *root)
{
    // Your code here
    vector<int> ds;
    left(root, 0, ds);
    return ds;
}