#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        while (left < right && nums[left] == nums[right]) {
            left++;
        }
        if (left == right || nums[left] < nums[right]) {
            break;
        }
        int mid = (left + right) / 2;
        if (nums[mid] < nums[left]) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return nums[left];
}

int main() {
    vector<int> nums = {2, 2, 2, 0, 1};
    int ans = findMin(nums);
    cout << ans << endl;
    return 0;
}
