#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        int ans = -1e9;
        deque<int> q;
        for (int i = 0; i < points.size(); i++) {
            while (!q.empty() && points[q.front()][0] < points[i][0] - k) q.pop_front();
            if (!q.empty()) ans = max(ans, points[i][1] + points[i][0] + points[q.front()][1] - points[q.front()][0]);

            while (!q.empty() && points[q.back()][1] - points[q.back()][0] <= points[i][1] - points[i][0]) q.pop_back();
            q.push_back(i);
        }
        return ans;
    }
};

int main() {
    Solution mySolution;
    vector<vector<int>> points = {{1,3},{2,0},{5,10},{6,-10}};
    int k = 1;
    int ans = mySolution.findMaxValueOfEquation(points, k);
    cout << ans << endl;
    return 0;
}
