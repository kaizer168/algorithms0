class Solution {
public:
    int maxDepth(TreeNode* root) {
        ans = 0;
        depth = 1;
        calc(root);
        return ans;
    }

private:
    void calc(TreeNode* root) {
        if (root == nullptr) return;
        ans = max(ans, depth);
        depth++;
        calc(root->left);
        calc(root->right);
        depth--;
    }

    int depth;
    int ans;
};
