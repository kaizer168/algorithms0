#include <iostream>
#include <vector>
using namespace std;

vector<int> searchRange(vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size();
    vector<int> ans;

    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] >= target) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    ans.push_back(right);

    left = -1;
    right = nums.size() - 1;
    while (left < right) {
        int mid = (left + right + 1) / 2;
        if (nums[mid] <= target) {
            left = mid;
        }
        else {
            right = mid - 1;
        }
    }
    ans.push_back(right);

    if (ans[0] > ans[1]) return {-1, -1};
    return ans;
}

int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> ans = searchRange(nums, 8);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    return 0;
}
