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
bool preorder(TreeNode *root, long lowerbound, long upperbound)
{
    if (root == NULL)
        return true;
    return (root->val > lowerbound && root->val < upperbound) && preorder(root->left, lowerbound, root->val) && preorder(root->right, root->val, upperbound);
}
bool isValidBST(TreeNode *root)
{
    return preorder(root, LONG_MIN, LONG_MAX);
}