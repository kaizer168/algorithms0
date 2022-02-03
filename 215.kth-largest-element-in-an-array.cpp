#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& a, int l, int r) {
    int pivot = l + rand() % (r - l + 1);
    int pivotVal = a[pivot];

    while (l <= r) {
        while (a[l] < pivotVal) l++;
        while (a[r] > pivotVal) r--;
        if (l == r) break;
        if (l < r) {
            int temp = a[l]; a[l] = a[r]; a[r] = temp;
            l++; r--;
        }
    }
    return r;
}

int quickSort(vector<int>& arr, int l, int r, int index) {
    if (l >= r) return arr[l];
    int pivot = partition(arr, l, r);
    if (index <= pivot) return quickSort(arr, l, pivot, index);
    else return quickSort(arr, pivot + 1, r, index);
}

int findKthLargest(vector<int>& nums, int k) {
    return quickSort(nums, 0, nums.size() - 1, nums.size() - k);
}

int main() {
    vector<int> vec = {3,2,1,5,6,4};
    int k = 2;
    int ans = findKthLargest(vec, k);
    cout << ans << endl;
    return 0;
}
