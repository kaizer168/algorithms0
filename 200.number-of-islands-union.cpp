#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void getFather(vector<vector<char>>& grid) {
        father = vector<int>(n + 1, 0);
        for (int i = 0; i < father.size(); i++) {
            father[i] = -1;
        }

        count = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < row; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    father[i * col + j] = i * col + j;
                }
            }
        }
    }

    int Find(int u) {
        if (u == father[u]) {
            return u;
        }
        else {
            father[u] = Find(father[u]);
            return father[u];
        }
    }

    void Union(int i, int j, int x, int y) {
        c1 = i * col + j;
        c2 = x * col + y;
        fc1 = Find(c1);
        fc2 = Find(c2);
        if (fc1 != fc2) {
            father[fc1] = fc2;
            count--;
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        row = grid.size();
        col = grid[0].size();
        n = row * col;
        count = 0;

        getFather(grid);
        int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1,0}};

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == '1') {
                    for (auto &dir : dirs) {
                        x = i + dir[0];
                        y = j + dir[1];
                        if (0 <= x && x < row && 0 <= y && y < col && grid[x][y] == '1') {
                            Union(i, j, x, y);
                        }
                    }
                }
            }
        }

        return count;
    }

private:
    vector<int> father;
    int c1;
    int c2;
    int fc1;
    int fc2;
    int count;
    int row;
    int col;
    int n;
    int x;
    int y;
};

int main() {
    Solution mySolution;
    vector<vector<char>> grid = {{'1','1','0','0','0'}, {'1','1','0','0','0'}, {'0','0','1','0','0'}, {'0','0','0','1','1'}};
    int ans = mySolution.numIslands(grid);
    cout << ans << endl;
    return 0;
}
