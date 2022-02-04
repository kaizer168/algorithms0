#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        this->n = n;
        this->k = k;
        recur(1);
        return ans;
    }

private:
    void recur(int i) {
        if (chosen.size() > k || chosen.size() + (n - i + 1) < k) return;
        if (i == n + 1) {
            if (chosen.size() == k) ans.push_back(chosen);
            return;
        }

        recur(i + 1);
        chosen.push_back(i);
        recur(i + 1);
        chosen.pop_back();
    }

    int n;
    int k;
    vector<int> chosen;
    vector<vector<int>> ans;
};

int main() {
    Solution mySolution;
    vector<vector<int>> ans = mySolution.combine(4,2);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
