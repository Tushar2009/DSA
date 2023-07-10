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
int maxSum(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int leftmax = max(0, maxSum(root->left, maxi));
    int rightmax = max(0, maxSum(root->right, maxi));
    int value = root->val;
    maxi = max(maxi, (leftmax + rightmax) + value);
    return max(leftmax, rightmax) + value;
}
int maxPathSum(TreeNode *root)
{
    int maxi = INT_MIN;
    maxSum(root, maxi);
    return maxi;
}