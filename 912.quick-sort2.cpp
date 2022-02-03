#include <iostream>
#include <vector>
#include <functional>
using namespace std;


vector<int> sortArray(vector<int>& nums) {
    cout << "enter sortArray" << endl;
  function<void(int, int)> quickSort = [&](int l, int r) {
    if (l >= r) return;
    int i = l;
    int j = r;
    int p = nums[l + rand() % (r - l + 1)];
    cout << "pivot = " << p << " pivotVal = " << nums[p] << endl;
    while (i <= j) {
      cout << "1: i = " << i << " j = " << j << endl;
      while (nums[i] < p) ++i;
      while (nums[j] > p) --j;
      cout << "2: i = " << i << " j = " << j << endl;
      cout << "nums[i] = " << nums[i] << " pivotVal = " << nums[p] << " nums[j] = " << nums[j] << endl;
      if (i <= j)
        swap(nums[i++], nums[j--]);
        cout << "exchange: nums[i] = " << nums[i-1] << " nums[j] = " << nums[j+1] << endl;
    }
    quickSort(l, j);
    quickSort(i, r);
  };
    quickSort(0, nums.size() - 1);
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
