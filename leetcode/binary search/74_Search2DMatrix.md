74. Search a 2D Matrix
    Solved
    Medium
    Topics
    premium lock icon
    Companies
    You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.

You must write a solution in O(log(m \* n)) time complexity.

Example 1:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
Example 2:

Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false

```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int up=0, down = matrix.size()-1;
        int row = -1;
        while(up<=down){
            int m = up + (down-up)/2;
            if(matrix[m][0]<=target && matrix[m][matrix[m].size()-1]>=target){
                row = m;
                break;
                }
            if(target < matrix[m][0]) down = m-1;
            else if (target > matrix[m][matrix[m].size()-1]) up = m+1;
        }
        if(row == -1) return 0;
        int l=0,r=matrix[row].size()-1;
        while(l<=r){
            int m = l+(r-l)/2;
            if(target > matrix[row][m]) l=m+1;
            else if(target < matrix[row][m]) r = m-1;
            else return 1;
        }
        return 0;
    }
};
```
