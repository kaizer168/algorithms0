#include <iostream>
#include <vector>
using namespace std;

bool validate(vector<int>& nums, int m, int size) {
    int box = 0;
    int count = 1;
    for (int num : nums) {
        if (box + num <= size) {
            box += num;
        }
        else {
            count++;
            box = num;
        }
    }
    return count <= m;
}

int splitArray(vector<int>& nums, int m) {
    int left = 0;
    int right = 0;
    for (int num : nums) {
        left = max(left, num);
        right += num;
    }
    while (left < right) {
        int mid = (left + right) / 2;
        if (validate(nums, m, mid)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return right;
}

int main() {
    vector<int> nums = {7,2,5,10,8};
    int m = 2;
    int ans = splitArray(nums, m);
    cout << ans << endl;
    return 0;
}
