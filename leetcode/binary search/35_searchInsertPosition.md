35. Search Insert Position
    Solved
    Easy
    Topics
    premium lock icon
    Companies
    Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [1,3,5,6], target = 5
Output: 2
Example 2:

Input: nums = [1,3,5,6], target = 2
Output: 1
Example 3:

Input: nums = [1,3,5,6], target = 7
Output: 4

```
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int l = 0, r = n-1;
        while(l<=r){
            int m = (l+r)/2;
            if(target == nums[m]) return m;
            if(target> nums[m]) l=m+1;
            else r = m-1;
        }
        return l;
    }
};
```
