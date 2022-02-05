class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 0) return {""};
        if (store.find(n) != store.end()) return store[n];
        vector<string> ans;
        for (int k = 1; k <= n; k++) {
            vector<string> A = generateParenthesis(k - 1);
            vector<string> B = generateParenthesis(n - k);
            for (string& a : A)
                for (string& b : B)
                    ans.push_back("(" + a + ")" + b);
        }
        store[n] = ans;
        return ans;
    }

private:
    unordered_map<int, vector<string>> store;
};
