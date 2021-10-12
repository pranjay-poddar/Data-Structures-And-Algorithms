/*Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.*/


class Solution {
public:
    void initHashSet(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                rows[i].insert(board[i][j]);
                cols[j].insert(board[i][j]);
                boxes[(i / 3) * 3 + j / 3].insert(board[i][j]);
            }
        }
    }
    
    bool isValidMove(int row, int col, char c) {
        if (rows[row].count(c)) {
            return false;
        }
        if (cols[col].count(c)) {
            return false;
        }
        if (boxes[(row / 3) * 3 + col / 3].count(c)) {
            return false;
        }
        return true;
    }
    
    void DoTheMove(vector<vector<char>>& board, int row, int col, char c) {
        board[row][col] = c;
        rows[row].insert(c);
        cols[col].insert(c);
        boxes[(row / 3) * 3 + col / 3].insert(c);
    }
    
    void UndoTheMove(vector<vector<char>>& board, int row, int col, char c) {
        board[row][col] = '.';
        rows[row].erase(c);
        cols[col].erase(c);
        boxes[(row / 3) * 3 + col / 3].erase(c);
    }
    
    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') 
                    continue;
                for (char c = '1'; c <= '9'; c++) {
                    if (!isValidMove(i, j, c)) {
                        continue;
                    }
                    DoTheMove(board, i, j, c);
                    if (solve(board)) {
                        return true;
                    }
                    UndoTheMove(board, i, j, c);
                }
                return false;
            }
        }
        return true;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        int len = board.size();
        initHashSet(board);
        solve(board);
    }
    
private:
    int len = 9;
    vector<unordered_set<char>> rows = vector<unordered_set<char>>(len, unordered_set<char>());
    vector<unordered_set<char>> cols = vector<unordered_set<char>>(len, unordered_set<char>());
    vector<unordered_set<char>> boxes = vector<unordered_set<char>>(len, unordered_set<char>()); 
};
