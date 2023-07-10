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
class BSTIterator
{
private:
    stack<TreeNode *> myStack;
    bool reverse = true;
    void pushAll(TreeNode *node)
    {
        for (; node != NULL;)
        {
            myStack.push(node);
            if (reverse)
            {
                node = node->right;
            }
            else
            {
                node = node->left;
            }
        }
    }

public:
    BSTIterator(TreeNode *root, bool isReverse)
    {
        reverse = isReverse;
        pushAll(root);
    }

    int next()
    {
        TreeNode *temp = myStack.top();
        myStack.pop();
        if (reverse)
            pushAll(temp->left);
        else
            pushAll(temp->right);
        return temp->val;
    }

    bool hasNext()
    {
        if (myStack.empty())
            return false;
        return true;
    }
};
class Solution
{
public:
    bool findTarget(TreeNode *root, int k)
    {
        if (root == NULL)
            return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i = l.next();
        int j = r.next();
        while (i < j)
        {
            if (i + j == k)
                return true;
            else if (i + j < k)
                i = l.next();
            else
            {
                j = r.next();
            }
        }
        return false;
    }
};