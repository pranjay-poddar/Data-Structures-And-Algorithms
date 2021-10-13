/*
N-Queens

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Constraints:
1 <= n <= 9
*/

class Solution
{
public:
    vector<vector<string>> res;
    bool isSafe(vector<string> &board, int x, int y)
    {
        for (int row = 0; row < x; row++)
        {
            if (board[row][y] == 'Q')
            {
                return false;
            }
        }
        int row = x; //for upper left diagonal
        int col = y;
        while (row >= 0 && col >= 0)
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            row--;
            col--;
        }
        row = x; //for upper right diagonal
        col = y;
        while (row >= 0 && col < board.size())
        {
            if (board[row][col] == 'Q')
            {
                return false;
            }
            row--;
            col++;
        }
        return true;
    }
    void NQueen(vector<string> &board, int x)
    {
        if (x == board.size())
        {
            res.push_back(board);
            return;
        }
        for (int col = 0; col < board.size(); col++)
        {
            if (isSafe(board, x, col))
            {
                board[x][col] = 'Q';

                NQueen(board, x + 1);
                board[x][col] = '.'; //backtracking
            }
        }
    }
    vector<vector<string>> solveNQueens(int n)
    {
        if (n <= 0)
        {
            return {{}};
        }
        vector<string> board(n, string(n, '.'));
        NQueen(board, 0);
        return res;
    }
};