37. Sudoku Solver
    Solved
    Hard
    Topics
    premium lock icon
    Companies
    Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.

Example 1:

Input: board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
Output: [["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
Explanation: The input board is shown above and the only valid solution is shown below:

```
class Solution {
public:
    bool safe(vector<vector<char>>& board, int r, int c, char num) {
        for (int i = 0; i < 9; i++) {
            if (board[i][c] == num || board[r][i] == num) return false;
        }
        int startRow = 3 * (r / 3), startCol = 3 * (c / 3);
        for (int i = startRow; i < startRow + 3; i++) {
            for (int j = startCol; j < startCol + 3; j++) {
                if (board[i][j] == num) return false;
            }
        }
        return true;
    }

    bool solve(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        if (safe(board, i, j, num)) {
                            board[i][j] = num;
                            if (solve(board)) return true; // base case reached
                            board[i][j] = '.'; // backtrack
                        }
                    }
                    return false; // No valid number found, trigger backtrack
                }
            }
        }
        return true; // Solved
    }

    void solveSudoku(vector<vector<char>>& board) {
        // sudoku(board,)
        solve(board);
    }
};
```
