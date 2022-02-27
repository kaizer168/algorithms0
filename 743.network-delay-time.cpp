#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        dist = vector<int>(n+1, 1e9);
        dist[k] = 0; 
        for (int round = 1; round <= n - 1; round++) {
            bool flag = false;
            for (vector<int>& edge : times) {
                int x = edge[0];
                int y = edge[1];
                int z = edge[2];
                if (dist[x] + z < dist[y]) {
                    dist[y] = dist[x] + z;
                    flag = true;
                }
            }
            if (!flag) break;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) ans = max(ans, dist[i]);
        return ans == 1e9 ? -1 : ans;
    }

private:
    vector<int> dist;
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
