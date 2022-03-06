#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        dfs(board);
    }

private:
    bool dfs(vector<vector<char>>& board) {
        if (!isValidSudoku(board)) return false;
        pair<int,int> pos = findFirstEmpty(board);
        int x = pos.first;
        int y = pos.second;
        if (x == -1) return true;
        for (char digit = '1'; digit <= '9'; digit++) {
            board[x][y] = digit;
            if (dfs(board)) return true;
            board[x][y] = '.';
            

        }
        return false;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> box[9];

        for (int i = 0; i < 9; i++) {
           for (int j = 0; j < 9; j++) {
               char digit = board[i][j];
               if (digit == '.') continue;
               if (row[i].find(digit) != row[i].end()) return false;
               row[i].insert(digit);
               if (col[j].find(digit) != col[j].end()) return false;
               col[j].insert(digit);
               int k = (i/3)*3+j/3;
               if (box[k].find(digit) != box[k].end()) return false;
               box[k].insert(digit);
           }
        }
        return true;
    }

    pair<int, int> findFirstEmpty(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) 
           for (int j = 0; j < 9; j++) {
               char digit = board[i][j];
               if (digit == '.') return {i, j};
           }
        return {-1, -1};
    }
};

int main() {
    Solution mySolution;
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}};
    mySolution.solveSudoku(board);
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[0].size(); j++) {
            cout << board[i][j] << ",";
        }
        cout << endl;
    }
    return 0;
}
