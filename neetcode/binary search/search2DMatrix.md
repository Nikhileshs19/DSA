Search a 2D Matrix
Solved
You are given an m x n 2-D integer array matrix and an integer target.

Each row in matrix is sorted in non-decreasing order.
The first integer of every row is greater than the last integer of the previous row.
Return true if target exists within matrix or false otherwise.

Can you write a solution that runs in O(log(m \* n)) time?

Example 1:

Input: matrix = [[1,2,4,8],[10,11,12,13],[14,20,30,40]], target = 10

Output: true

```
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l=0,r=matrix.size()-1;
        int temp = 0;
        while(l<=r){
            int m = (l+r)/2;
            if(target > matrix[m][matrix[0].size()-1])
                l=m+1;
            else if(target < matrix[m][0])
                r = m-1;
            else{
            temp = m;
                break;
            }

        }
        l=0;
        r=matrix[0].size()-1;
        while(l<=r){
            int m = (l+r)/2;
            if(matrix[temp][m]==target)
                return 1;
            else if(matrix[temp][m]>target)
                r=m-1;
            else
                l=m+1;
        }
        return 0;
    }
};
```
