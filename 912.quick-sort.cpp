#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& a, int l, int r) {
    cout << "enter partition" << endl;
    int pivot = l + rand() % (r - l + 1);
    int pivotVal = a[pivot];
    cout << "pivot = " << pivot << " pivotVal = " << pivotVal << endl;

    while (l <= r) {
        cout << "1: l = " << l << " r = " << r << endl;
        while (a[l] < pivotVal) l++;
        while (a[r] > pivotVal) r--;
        cout << "2: l = " << l << " r = " << r << endl;
        cout << "a[l] = " << a[l] << " pivotVal = " << pivotVal << " a[r] = " << a[r] << endl;
        if (l == r) break;
        if (l < r) {
            int temp = a[l]; a[l] = a[r]; a[r] = temp;
            cout << "exchange: a[l] = " << a[l] << " a[r] = " << a[r] << endl;
            l++; r--;
        }
    }

    cout << "exit partition" << endl;
    return r;
}

void quickSort(vector<int>& arr, int l, int r) {
    cout << "enter quickSort" << endl;
    if (l >= r) return;
    int pivot = partition(arr, l, r);
    cout << "pivot = " << pivot << endl;
    quickSort(arr, l, pivot);
    quickSort(arr, pivot + 1, r);
    cout << "exit quickSort" << endl;
}

vector<int> sortArray(vector<int>& nums) {
    cout << "enter sortArray" << endl;
    quickSort(nums, 0, nums.size() - 1);
    cout << "exit sortArray" << endl;
    return nums;
}

int main() {
    vector<int> vec_in = {-4,0,7,4,9,-5,-1,0,-7,-1};
    vector<int> vec = sortArray(vec_in);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    return 0;
}
