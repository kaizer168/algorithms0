#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        n = nums.size();
        recur(nums, 0);
        return ans;
    }

private:
    void recur(vector<int>& nums, int i) {
        if (i == n) {
            ans.push_back(chosen);
            return;
        }

        recur(nums, i + 1);
        chosen.push_back(nums[i]);
        recur(nums, i + 1);
        chosen.pop_back();
    }

    int n;
    vector<int> chosen;
    vector<vector<int>> ans;
};

int main() {
    vector<int> nums = {1,2,3};
    Solution mySolution;
    vector<vector<int>> ans = mySolution.subsets(nums);

    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
