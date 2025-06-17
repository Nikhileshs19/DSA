153. Find Minimum in Rotated Sorted Array
     Solved
     Medium
     Topics
     premium lock icon
     Companies
     Hint
     Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.
Example 2:

Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
Example 3:

```
class Solution {
public:
    int findMin(vector<int>& nums) {
        // int l = 0, r = nums.size() - 1;
        // while (l <= r) {
        //     int m = l + (r - l) / 2;
        //     if(nums[m]>nums[l]){
        //         if(target < nums[m] && target >= nums[l]) r = m -1;
        //         else l = m+1;
        //     }
        //     else{
        //         if(target > nums[m] && target <= nums[r])
        //             l=m+1;
        //         else r = m-1;
        //     }
        // }
        sort(nums.begin(),nums.end());
        return nums[0];
    }
};
```
