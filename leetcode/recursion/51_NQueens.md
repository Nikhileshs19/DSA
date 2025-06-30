51. N-Queens
    Solved
    Hard
    Topics
    premium lock icon
    Companies
    The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example 1:

Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above
Example 2:

Input: n = 1
Output: [["Q"]]

```
class Solution {
public:
    bool isSafePlace(int n, vector<string>&cur, int r, int c){
        for(int i=0;i<n;i++){
            if(cur[i][c] == 'Q') return 0;
        }
        for(int i=r-1, j=c-1;i>=0 && j>=0;i--,j--){
            if(cur[i][j]=='Q') return 0;
        }
        for(int i=r-1,j=c+1;i>=0 && j<n;i--,j++)
            if(cur[i][j]=='Q') return 0;
        return 1;
    }

    void solveNQueens(int n, vector<vector<string>>&ans,vector<string>&cur, int row){
        if(row == n) {
            ans.push_back(cur);
            return;
        }
        for(int col=0;col<n;col++){
            if(isSafePlace(n,cur,row,col)){
                cur[row][col]='Q';
                solveNQueens(n,ans,cur,row+1);
                cur[row][col]='.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> nQueens(n,string(n,'.'));
        solveNQueens(n,ans,nQueens,0);
        return ans;

    }
};
```
