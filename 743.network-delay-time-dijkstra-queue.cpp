#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        ver = vector<vector<int>>(n + 1, vector<int>());
        edge = vector<vector<int>>(n + 1, vector<int>());
        for (vector<int>& t : times) {
            int x = t[0];
            int y = t[1];
            int z = t[2];
            ver[x].push_back(y);
            edge[x].push_back(z);
        }

        dist = vector<int>(n + 1, 1e9);
        dist[k] = 0; 
        expand = vector<bool>(n + 1, false);
        q.push({0, k});
        while (!q.empty()) {
            int x = q.top().second;
            q.pop();
            if (expand[x]) continue;
            expand[x] = true;
            for (int i = 0; i < ver[x].size(); i++) {
                int y = ver[x][i];
                int z = edge[x][i];
                if (dist[y] > dist[x] + z) {
                    dist[y] = dist[x] + z;
                    q.push({-dist[y], y});
                }
            }
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) ans = max(ans, dist[i]);
        return ans == 1e9 ? -1 : ans;
    }

private:
    vector<int> dist;
    vector<bool> expand;
    vector<vector<int>> ver;
    vector<vector<int>> edge;
    priority_queue<pair<int, int>> q;
};

int main() {
    Solution mySolution;
    vector<vector<int>> times = {{2,1,1},{2,3,1},{3,4,1}};
    int n = 4;
    int k = 2;
    int ans = mySolution.networkDelayTime(times, n, k);
    cout << ans << endl;
    return 0;
}
