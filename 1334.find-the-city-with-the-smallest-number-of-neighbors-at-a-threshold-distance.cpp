#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX / 2));
        for (const auto& e : edges) {
            dp[e[0]][e[1]] = dp[e[1]][e[0]] = e[2];
            }

        for (int k = 0; k < n; ++k)
            for (int u = 0; u < n; ++u)
                for (int v = 0; v < n; ++v)
                    dp[u][v] = min(dp[u][v], dp[u][k] + dp[k][v]);

        int ans = -1;
        int min_nb = INT_MAX;
        for (int u = 0; u < n; ++u) {
            int nb = 0;
            for (int v = 0; v < n; ++v)
                if (v != u && dp[u][v] <= distanceThreshold)
                    ++nb;
            if (nb <= min_nb) {
                min_nb = nb;
                ans = u;
            }
        }
        return ans;
    }
};

int main() {
    Solution mySolution;
    int n = 5;
    vector<vector<int>> edges = {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}};
    int distanceThreshold = 2;
    int ans = mySolution.findTheCity(n, edges, distanceThreshold);
    cout << ans << endl;
    return 0;
}
