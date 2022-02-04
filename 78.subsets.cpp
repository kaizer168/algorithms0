#include <iostream>
#include <vector>
using namespace std;

void recur(vector<int>& nums, int i, int n, vector<vector<int>>& ans) {
    vector<int> chosen;
    if (i == n) {
        ans.push_back(chosen);
        return;
    }

    recur(nums, i + 1, n, ans);
    chosen.push_back(nums[i]);
    recur(nums, i + 1, n, ans);
    chosen.pop_back();
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> ans;
    int n = nums.size();
    recur(nums, 0, n, ans);
    return ans;
}

int main() {
    vector<int> nums = {1,2,3};
    vector<vector<int>> ans = subsets(nums);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

