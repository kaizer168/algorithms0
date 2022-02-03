#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    sort(intervals.begin(), intervals.end(),
        [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
    vector<vector<int>> ans;
    int farthest = -1;
    int start = -1;
    for (const vector<int>& interval : intervals) {
        int left = interval[0];
        int right = interval[1];
        if (left <= farthest) {
            farthest = max(farthest, right);
        }
        else {
            if (farthest != -1) {
                ans.push_back({start, farthest});
            }
            start = left;
            farthest = right;
        }
    }
    ans.push_back({start, farthest});
    return ans;
}

int main() {
    vector<vector<int>> vec = {{1,3},{2,6},{8,10},{15,18}};
    vector<vector<int>> ans = merge(vec);
    for (int i = 0; i < ans.size(); i++) {
        for (int j = 0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
