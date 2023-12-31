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
vector<vector<int>> verticalTraversal(TreeNode *root)
{
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<TreeNode *, pair<int, int>>> q;
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        TreeNode *cur = it.first;
        // x -> vertical , y->level
        int x = it.second.first, y = it.second.second;
        nodes[x][y].insert(cur->val);
        if (cur->left != NULL)
        {
            q.push({cur->left, {x - 1, y + 1}});
        }
        if (cur->right != NULL)
        {
            q.push({cur->right, {x + 1, y + 1}});
        }
    }
    vector<vector<int>> ans;
    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
