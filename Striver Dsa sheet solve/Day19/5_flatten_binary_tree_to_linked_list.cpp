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
// Time Complexity: O(N)

// Reason: We are doing a simple preorder traversal.

// Space Complexity: O(N)

// Reason: Worst case time complexity will be O(N) (in case of skewed tree).
class Solution
{
public:
    TreeNode *prev = NULL;
    void flatten(TreeNode *root)
    {
        if (root == NULL)
            return;
        flatten(root->right);
        flatten(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};
// Time Complexity: O(N)

// Reason: Time complexity will be the same as that of a morris traversal

// Space Complexity: O(1)

// Reason: We are not using any extra space.
void flatten(TreeNode *root)
{
    TreeNode *cur = root;
    while (cur)
    {
        if (cur->left)
        {
            TreeNode *pre = cur->left;
            while (pre->right)
            {
                pre = pre->right;
            }
            pre->right = cur->right;
            cur->right = cur->left;
            cur->left = NULL;
        }
        cur = cur->right;
    }
}