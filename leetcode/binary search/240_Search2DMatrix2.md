240. Search a 2D Matrix II
     Solved
     Medium
     Topics
     premium lock icon
     Companies
     Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.

Example 1:

Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
Output: true

```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int r = 0, c= matrix[0].size()-1;
        while(r<matrix.size() && c>=0){
            if(matrix[r][c] == target) return 1;
            matrix[r][c] > target ? c-- : r++;

        }
        return 0;
    }
};
```
