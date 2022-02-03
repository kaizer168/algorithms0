#include <iostream>
using namespace std;

double myRealSqrt(double x) {
    double left = 1;
    double right = x;
    while (right - left > 1e-7) {
        double mid = left + (right - left + 1) / 2;
        if (mid * mid <= x) {
            left = mid;
        }
        else {
            right = mid;
        }
    }
    return right;
}

int mySqrt(int x) {
    return (int)(myRealSqrt(x));
}

int main() {
    int ans = mySqrt(4);
    cout << ans << endl;
    return 0;
}
