Climbing Stairs
Solved
You are given an integer n representing the number of steps to reach the top of a staircase. You can climb with either 1 or 2 steps at a time.

Return the number of distinct ways to climb to the top of the staircase.

Example 1:

Input: n = 2

Output: 2
Explanation:

1 + 1 = 2
2 = 2

```
class Solution {
public:
    int climbStairs(int n) {
        int oneBack = 1, twoBack = 1;
        for(int i=0;i<n-1;i++){
            int temp = oneBack;
            oneBack = oneBack+twoBack;
            twoBack = temp;
        }
        return oneBack;
    }
};
```
