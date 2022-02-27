#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);

        for (int i = 1; i < nums.size(); ++i) {
            dp[i] = max(dp[i - 1], nums[i - 1]) - 1;
            if (dp[i] < 0) return false;
        }
        return true;
    }
};

int main() {
    Solution mySolution;
    vector<int> jump = {2,3,1,1,4};
    bool ans = mySolution.canJump(jump);
    cout << ans << endl;
    return 0;
}
