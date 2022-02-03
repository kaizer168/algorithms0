#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<pair<int, int>> events;
    for (const vector<int>& interval : intervals) {
        events.push_back({interval[0], 1});
        events.push_back({interval[1] + 1, -1});
    }
    sort(events.begin(), events.end());
    int covering = 0;
    int start;
    vector<vector<int>> ans;
    for (const pair<int, int>& event : events) {
        if (covering == 0) start = event.first;
        covering += event.second;
        if (covering == 0) {
            ans.push_back({start, event.first - 1});
        }
    }
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
