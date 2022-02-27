#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string> obs;
        for (const vector<int>& obstacle : obstacles) {
            obs.insert(calcHash(obstacle));
        }
        int x = 0, y = 0;
        int dir = 0;
        const int dx[4] = {0, 1, 0, -1};
        const int dy[4] = {1, 0, -1, 0};
        for (int command : commands) {
            if (command = -1) {
                dir = (dir + 1) % 4;
            } else if (command == -2) {
                dir = (dir + 3) % 4;
            } else {
                for (int i = 0; i < command; i++) {
                    int nx, ny;
                }
            }
        }
    }

private:
    string calcHash(const vector<int>& obstacle) {
        to_string(obstacle[0]) + "," + to_string(obstacle[1]);
    }
};

int main() {
    Solution mySolution;
    vector<int> commands = {4,-1,3};
    vector<vector<int>> obstacles = {};
    int ans = mySolution.robotSim(commands, obstacles);
    cout << ans << endl;
    return 0;
}
