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
TreeNode *buildTree(vector<int> &postorder, int postStart, int postEnd, vector<int> &inorder, int inStart, int inEnd, map<int, int> &imap)
{
    if (postStart > postEnd || inStart > inEnd)
        return NULL;
    TreeNode *root = new TreeNode(postorder[postEnd]);
    int inRoot = imap[postorder[postEnd]];
    int numleft = inRoot - inStart;
    root->left = buildTree(postorder, postStart, postStart + numleft - 1, inorder, inStart, inRoot - 1, imap);
    root->right = buildTree(postorder, postStart + numleft, postEnd - 1, inorder, inRoot + 1, inEnd, imap);
    return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    map<int, int> imap;
    for (int i = 0; i < inorder.size(); i++)
    {
        imap[inorder[i]] = i;
    }
    TreeNode *root = buildTree(postorder, 0, postorder.size() - 1, inorder, 0, inorder.size() - 1, imap);
    return root;
}