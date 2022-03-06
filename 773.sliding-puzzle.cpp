#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        string start = zip(board);
        string target = zip({{1,2,3},{4,5,0}});
        q.push(start);
        depth[start] = 0;
        while (!q.empty()) {
            string s = q.front();
            q.pop();
            int pos = findZeroIndex(s);
            if (pos >= 3) expand(s, pos, pos - 3);
            if (pos <= 2) expand(s, pos, pos + 3);
            if (pos % 3 != 0) expand(s, pos, pos - 1);
            if (pos % 3 != 2) expand(s, pos, pos + 1);
            if (depth.find(target) != depth.end()) return depth[target];
        }
        return -1;
    }

private:
    void expand(string& s, int pos, int other) {
        string ns = s;
        swap(ns[pos], ns[other]);
        if (depth.find(ns) != depth.end()) return;
        depth[ns] = depth[s] + 1;
        q.push(ns);
    }

    string zip(const vector<vector<int>>& board) {
        string res;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                res += '0' + board[i][j];
        return res;
    }

    int findZeroIndex(string& s) {
        for (int i = 0; i < 6; i++) if (s[i] == '0') return i;
        return -1;
    }

    queue<string> q;
    unordered_map<string, int> depth;
};

int main() {
    Solution mySolution;
    vector<vector<int>> board = {{1,2,3},{4,0,5}};
    int ans = mySolution.slidingPuzzle(board);
    cout << ans << endl;
    return 0;
}
