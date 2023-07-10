#include <bits/stdc++.h>
using namespace std;
// Time Complexity: O(N)

// Space Complexity: O(1) Extra Space + O(H) Recursion Stack space, where “H”  is the height of the binary tree.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int preorder(TreeNode *root, int &diameter)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = preorder(root->left, diameter);
    int rh = preorder(root->right, diameter);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}
int diameterOfBinaryTree(TreeNode *root)
{
    int diameter = INT_MIN;
    preorder(root, diameter);
    return diameter;
}