Binary Search
Solved
You are given an array of distinct integers nums, sorted in ascending order, and an integer target.

Implement a function to search for target within nums. If it exists, then return its index, otherwise, return -1.

Your solution must run in
O
(
l
o
g
n
)
O(logn) time.

Example 1:

Input: nums = [-1,0,2,4,6,8], target = 4

Output: 3

```
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,r=nums.size()-1;
        while(l<=r){
            int m = (l+r)/2;
            if(target == nums[m])
                return m;
            else if(target > nums[m])
                l = m+1;
            else
                r = m-1;
        }
        return -1;
    }
};
```
