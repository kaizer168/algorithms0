#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    vector<int> count(1001, 0);
    for (int val : arr1) {
        count[val]++;
    }
    vector<int> ans;
    for (int val : arr2) {
        while (count[val] > 0) {
            ans.push_back(val);
            count[val]--;
        }
    }

    for (int val = 0; val <= 1000; val++) {
        while (count[val] > 0) {
            ans.push_back(val);
            count[val]--;
        }
    }
    return ans;
}

int main() {
    vector<int> arr1 = {2,3,1,3,2,4,6,7,9,2,19};
    vector<int> arr2 = {2,1,4,3,9,6};
    vector<int> ans = relativeSortArray(arr1, arr2);

    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}
