#include <iostream>
#include <vector>
using namespace std;

int mySqrt(int x) {
    int left = 0;
    int right = x;

    while (left < right) {
        int mid = left + (right - left + 1) / 2;
        if (mid <= x / mid) {
            left = mid;
        }
        else {
            right = mid - 1;
        }
    }
    return right;
}

int main() {
    int ans = mySqrt(8);
    cout << ans << endl;
    return 0;
}
