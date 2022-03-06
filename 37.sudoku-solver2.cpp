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
        for (int i = 0; i < 9; i++)
            for (int digit = 1; digit <= 9; digit++)
                row[i][digit] = col[i][digit] = box[i][digit] = true;
        for (int i = 0; i < 9; i++) 
           for (int j = 0; j < 9; j++) {
               if (board[i][j] == '.') continue;
               int digit = board[i][j] - '0';
               row[i][digit] = false;  
               col[j][digit] = false;  
               box[boxIndex(i, j)][digit] = false;
           }
        dfs(board);
    }

private:
    bool dfs(vector<vector<char>>& board) {
        pair<int,int> pos = findMinimumProbability(board);
        int x = pos.first;
        int y = pos.second;
        if (x == -1) return true;
        vector<int> availableDigits = getAvailableDigits(x, y);
        for (int digit : availableDigits) {
            board[x][y] = '0' + digit;
            row[x][digit] = false;
            col[y][digit] = false;
            box[boxIndex(x, y)][digit] = false;
            if (dfs(board)) return true;
            box[boxIndex(x, y)][digit] = true;
            col[y][digit] = true;
            row[x][digit] = true;
            board[x][y] = '.';
        }
        return false;
    }

    pair<int, int> findMinimumProbability(vector<vector<char>>& board) {
        int minValue = 10;
        pair<int,int> pos = {-1, -1};
        for (int i = 0; i < 9; i++) 
           for (int j = 0; j < 9; j++) {
               if (board[i][j] != '.') continue;
               vector<int> availableDigits = getAvailableDigits(i, j);
               if (availableDigits.size() < minValue) {
                   minValue = availableDigits.size();
                   pos = {i, j};
               }
           }
        return pos;
    }

    vector<int> getAvailableDigits(int i, int j) {
        vector<int> availableDigits;
        for (int digit = 1; digit <= 9; digit++) {
            if (row[i][digit] && col[j][digit] && box[boxIndex(i, j)][digit])
                availableDigits.push_back(digit);
        }
        return availableDigits;
    }

    int boxIndex(int i, int j) { return (i/3)*3+(j/3); }

    bool row[9][10];
    bool col[9][10];
    bool box[9][10];
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
