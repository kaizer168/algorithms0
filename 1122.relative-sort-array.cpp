#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
    unordered_map<int, int> arr2orders;
    for (int i = 0; i < arr2.size(); i++) {
        arr2orders[arr2[i]] = i;
    }
    sort(arr1.begin(), arr1.end(), [&](int x, int y) {
        int xPos = arr2orders.find(x) != arr2orders.end() ? arr2orders[x] : arr2.size();
        int yPos = arr2orders.find(y) != arr2orders.end() ? arr2orders[y] : arr2.size();
        return xPos < yPos || (xPos == yPos && x < y);
    });
    return arr1;
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
