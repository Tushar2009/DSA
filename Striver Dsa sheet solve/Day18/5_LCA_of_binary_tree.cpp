#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Time complexity: O(N) where n is the number of nodes.

// Space complexity: O(N), auxiliary space.
TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL || root == p || root == q)
    {
        return root;
    }
    TreeNode *leftnode = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightnode = lowestCommonAncestor(root->right, p, q);
    if (leftnode == NULL)
    {
        return rightnode;
    }
    if (rightnode == NULL)
    {
        return leftnode;
    }
    else
    {
        return root;
    }
}