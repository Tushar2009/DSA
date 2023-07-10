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
// Time Complexity: O(N).

// Reason: The time complexity will be O(H) + O(H) + O(N) which is ≈ O(N)

// Space Complexity: O(N)

// Reason: Space is needed for the recursion stack while adding leaves. In the worst case (skewed tree), space complexity can be O(N).

bool isLeaf(TreeNode<int> *root)
{
    if (root->left == NULL && root->right == NULL)
        return true;
    return false;
}
void addLeftBoundary(TreeNode<int> *root, vector<int> &res)
{
    TreeNode<int> *cur = root->left;
    while (cur != NULL)
    {
        if (!isLeaf(cur))
            res.push_back(cur->data);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}
void addLeaves(TreeNode<int> *root, vector<int> &res)
{
    if (isLeaf(root))
    {
        res.push_back(root->data);
        return;
    }
    if (root->left)
        addLeaves(root->left, res);
    if (root->right)
        addLeaves(root->right, res);
}
void addRightBoundary(TreeNode<int> *root, vector<int> &res)
{
    TreeNode<int> *cur = root->right;
    stack<int> st;
    while (cur)
    {
        if (!isLeaf(cur))
            st.push(cur->data);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
    // Write your code here.
    vector<int> res;
    if (root == NULL)
        return res;
    if (!isLeaf(root))
        res.push_back(root->data);
    addLeftBoundary(root, res);
    addLeaves(root, res);
    addRightBoundary(root, res);

    return res;
}