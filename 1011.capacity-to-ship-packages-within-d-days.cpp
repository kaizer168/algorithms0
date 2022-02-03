#include <iostream>
#include <vector>
using namespace std;

int shipDays(vector<int>& weights, int days) {
    int left = 0;
    int right = 0;

    for (int w: weights) {
        left = max(left, w);
        right += w;
    }
    while (left < right) {
        int mid = (left + right) / 2;
        int requirement = 1;
        int tillnow = 0;
        for (int w: weights) {
            if (tillnow + w > mid) {
                requirement += 1;
                tillnow = 0;
            }
            tillnow += w;
        }
        if (requirement <= days) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    vector<int> nums = {1,2,3,1,1,};
    int D = 4;
    cout << shipDays(nums, D) << endl;
    return 0;
}
