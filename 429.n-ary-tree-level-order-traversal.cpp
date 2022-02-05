/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if (!root) return ans;
        q.push(make_pair(root, 0));
        while(!q.empty()) {
            Node* node = q.front().first;
            int depth = q.front().second;
            q.pop();

            if (depth == ans.size()) {
                ans.push_back({node->val});
            }
            else {
                ans[depth].push_back(node->val);
            }

            for (Node* child : node->children) {
                q.push(make_pair(child, depth + 1));
            }
        }
        return ans;
    }

    queue<pair<Node*, int>> q;
    vector<vector<int>> ans;
};
