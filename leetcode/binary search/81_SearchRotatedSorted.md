81. Search in Rotated Sorted Array II
    Solved
    Medium
    Topics
    premium lock icon
    Companies
    There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.

Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false

```
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int m = l + (r - l) / 2;
            if (target == nums[m]) return 1;
            if(nums[l]==nums[m]){
                 l++;
                 continue;
            }
            if(nums[m]>nums[l]){
                if(target < nums[m] && target >= nums[l]) r = m -1;
                else l = m+1;
            }
            else{
                if(target > nums[m] && target <= nums[r])
                    l=m+1;
                else r = m-1;
            }
        }
        return 0;
    }
};
```
