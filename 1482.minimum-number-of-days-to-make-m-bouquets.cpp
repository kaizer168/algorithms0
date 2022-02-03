#include <iostream>
#include <vector>
using namespace std;

bool validateOnDay(vector<int>& bloomDay, int m, int k, int now) {
    int bouquet = 0;
    int consecutive = 0;
    for (int bloom : bloomDay) {
        if (bloom <= now) {
            consecutive++;
            if (consecutive == k) {
                bouquet++;
                consecutive = 0;
            }
        }
        else {
            consecutive = 0;
        }
    }
    return bouquet >= m;
}

int minDays(vector<int>& bloomDay, int m, int k) {
    int latestBloom = 0;
    for (int bloom : bloomDay) {
        latestBloom = max(latestBloom, bloom);
    }
    int left = 0;
    int right = latestBloom + 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (validateOnDay(bloomDay, m, k, mid)) {
            right = mid;
        }
        else {
            left = mid + 1;
        }
    }
    if (right == latestBloom + 1) return -1;
    return right;
}

int main() {
    vector<int> bloomDay = {1,10,3,10,2};
    int m = 3;
    int k = 1;

    int ans = minDays(bloomDay, m, k);
    cout << ans << endl;

    return 0;
}

