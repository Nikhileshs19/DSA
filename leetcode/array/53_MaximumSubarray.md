Code
Testcase
Testcase
Test Result 53. Maximum Subarray
Solved
Medium
Topics
premium lock icon
Companies
Given an integer array nums, find the subarray with the largest sum, and return its sum.

Example 1:

Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.
Example 2:

Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.

```
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = nums[0];
        int max_ending_here = nums[0];

        for (size_t i = 1; i < nums.size(); ++i) {
            max_ending_here = max(nums[i], max_ending_here + nums[i]);
            max_so_far = max(max_so_far, max_ending_here);
        }

        return max_so_far;
    }
};
```
