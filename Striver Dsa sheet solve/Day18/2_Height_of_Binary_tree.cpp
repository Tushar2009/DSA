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
int preorder(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int lh = preorder(root->left);
    int rh = preorder(root->right);
    return 1 + max(lh, rh);
}
int maxDepth(TreeNode *root)
{
    return preorder(root);
}