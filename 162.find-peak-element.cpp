#include <iostream>
#include <vector>

using namespace std;

int findPeakElement(vector<int>& nums) {
    int left = 0;
    int right = nums.size() -1;
    while (left < right) {
        int lmid = (left + right) / 2;
        int rmid = lmid + 1;
        if (nums[lmid] <= nums[rmid]) left = lmid + 1;
        else right = rmid - 1;
    }
    return right;
}

int main() {
    vector<int> nums = {1,2,3,1};
    int ans = findPeakElement(nums);
    cout << ans << endl;
    return 0;
}
