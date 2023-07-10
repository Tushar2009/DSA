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
TreeNode *buildTree(vector<int> &preorder, int preStart, int preEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &imap)
{
    if (preStart > preEnd || inStart > inEnd)
        return NULL;
    TreeNode *root = new TreeNode(preorder[preStart]);
    int inRoot = imap[root->val];
    int numleft = inRoot - inStart;
    root->left = buildTree(preorder, preStart + 1, preStart + numleft, inorder, inStart, inRoot - 1, imap);
    root->right = buildTree(preorder, preStart + numleft + 1, preEnd, inorder, inRoot + 1, inEnd, imap);
    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    map<int, int> imap;
    for (int i = 0; i < inorder.size(); i++)
    {
        imap[inorder[i]] = i;
    }
    TreeNode *root = buildTree(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, imap);
    return root;
}