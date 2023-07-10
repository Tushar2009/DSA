#include <bits/stdc++.h>
using namespace std;
template <typename T>
class TreeNode
{
public:
    T data;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
            delete left;
        if (right)
            delete right;
    }
};
class NodeValue
{
public:
    int maxNode, minNode, maxSize;
    NodeValue(int maxi, int mini, int size)
    {
        maxNode = maxi;
        minNode = mini;
        maxSize = size;
    }
};
NodeValue largestBSTHelper(TreeNode<int> *root)
{
    if (root == NULL)
    {
        return NodeValue(INT_MIN, INT_MAX, 0);
    }
    auto left = largestBSTHelper(root->left);
    auto right = largestBSTHelper(root->right);
    if (left.maxNode < root->data && root->data < right.minNode)
    {
        return NodeValue(max(right.maxNode, root->data), min(root->data, left.minNode), left.maxSize + right.maxSize + 1);
    }
    return NodeValue(INT_MAX, INT_MIN, max(left.maxSize, right.maxSize));
}
int largestBST(TreeNode<int> *root)
{
    // Write your code here.
    return largestBSTHelper(root).maxSize;
}