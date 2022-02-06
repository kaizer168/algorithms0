/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        this->p = p;
        this->q = q;
        dfs(root);
        return ans;
    }

private:
    TreeNode* p;
    TreeNode* q;
    TreeNode* ans;

    pair<bool, bool> dfs(TreeNode* root) {
        if (root == nullptr) return {false, false};
        pair<bool, bool> leftResult = dfs(root->left);
        pair<bool, bool> rightResult = dfs(root->right);
        pair<bool, bool> result;
        result.first = leftResult.first || rightResult.first || root->val == p->val;
        result.second = leftResult.second || rightResult.second || root->val == q->val;
        if (result.first && result.second && ans == nullptr) ans = root;
        return result;
    }
};
