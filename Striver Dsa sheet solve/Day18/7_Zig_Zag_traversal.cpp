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
vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    if (!root)
        return {};
    vector<vector<int>> ans;
    queue<TreeNode *> q;
    q.push(root);
    bool right = false;
    while (!q.empty())
    {
        int sz = q.size();
        vector<int> temp;
        while (sz-- > 0)
        {
            TreeNode *node = q.front();
            q.pop();
            temp.push_back(node->val);
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        if (right)
            reverse(temp.begin(), temp.end());
        ans.push_back(temp);
        right = !right;
    }
    return ans;
}