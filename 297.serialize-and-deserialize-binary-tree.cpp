/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream seq;
        sdfs(seq, root);
        return seq.str();
    }

    void sdfs(ostringstream& seq, TreeNode* root) {
        if (root == nullptr) {
            seq << "null ";
            return;
        }
        seq << root->val << " ";
        sdfs(seq, root->left);
        sdfs(seq, root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return ddfs(in);
    }

    TreeNode* ddfs(istringstream& in) {
        string val;
        in >> val;
        if (val == "null") return nullptr;
        TreeNode* root = new TreeNode(stoi(val));
        root->left = ddfs(in);
        root->right = ddfs(in);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
