130. Surrounded Regions
     Solved
     Medium
     Topics
     premium lock icon
     Companies
     You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:

Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: The region is surrounded with 'X' cells if you can connect the region with 'X' cells and none of the region cells are on the edge of the board.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

Example 1:

Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]

Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]

Explanation:

In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

Example 2:

Input: board = [["X"]]

Output: [["X"]]

```
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        for(int i=0;i<n;i++){
            if(board[0][i] == 'O') dfs(board,0,i);
            if(board[m-1][i] == 'O') dfs(board,m-1,i);
        }
        for(int i=0;i<m;i++){
            if(board[i][0] == 'O') dfs(board,i,0);
            if(board[i][n-1] == 'O') dfs(board,i,n-1);
        }
        for(int i=0;i<m;i++){
            for(int j=0; j<n;j++){
                if(board[i][j] == 'O') board[i][j]='X';
                if(board[i][j] == 'L') board[i][j]='O';
            }
        }
    }
    void dfs(vector<vector<char>>&board, int i, int j){
        if(i < 0 || i>=board.size() || j <0 || j>=board[0].size() || board[i][j]!='O') return;
        board[i][j]='L';
        dfs(board,i+1,j);
        dfs(board,i-1,j);
        dfs(board,i,j+1);
        dfs(board,i,j-1);
    }
};
```
