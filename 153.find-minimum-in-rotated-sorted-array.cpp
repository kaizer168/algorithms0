#include <iostream>
#include <vector>
using namespace std;

int findMin(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;

    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] <= nums[right]) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return nums[right];
}

int main() {
    vector<int> nums = {3, 4, 5, 1, 2};
    int ans = findMin(nums);
    cout << ans << endl;
    return 0;
}
