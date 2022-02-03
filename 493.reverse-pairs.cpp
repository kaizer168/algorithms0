#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int left, int mid, int right) {
    vector<int> temp = {};
    int i = left, j = mid + 1;

    for (int k = 0; k < temp.size(); k++) {
        if (j > right || (i <= mid && arr[i] <= arr[j]))
            temp[k] = arr[i++];
        else
            temp[k] = arr[j++];
    }
    for (int k = 0; k < temp.size(); k++) {
        arr[left + k] = temp[k];
    }

}

void calculate(vector<int>& arr, int left, int mid, int right, int& ans) {
    ans = 0;
    int j = mid;
    for (int i = left; i <= mid; i++) {
        while (j < right && arr[i] > 2 * arr[j + 1]) j++;
        ans += j - mid;
    }
}

void mergeSort(vector<int>& arr, int l, int r, int& ans) {
    ans = 0;
    if (l >= r) return;
    int mid = l + (r - l) / 2;
    mergeSort(arr, l, mid, ans);
    mergeSort(arr, mid + 1, r, ans);
    calculate(arr, l, mid, r, ans);
    merge(arr, l, mid, r);
}

int reversePairs(vector<int>& nums) {
    int ans = 0;
    mergeSort(nums, 0, nums.size() - 1, ans);
    return ans;
}

int main() {
    vector<int> vec = {1,3,2,3,1};
    int ans = reversePairs(vec);
    cout << ans << endl;

    return 0;
}
