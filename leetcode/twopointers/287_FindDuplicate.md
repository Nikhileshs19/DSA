287. Find the Duplicate Number
     Solved
     Medium
     Topics
     premium lock icon
     Companies
     Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and using only constant extra space.

Example 1:

Input: nums = [1,3,4,2,2]
Output: 2
Example 2:

Input: nums = [3,1,3,4,2]
Output: 3
Example 3:

Input: nums = [3,3,3,3,3]
Output: 3

```
class Solution {
public:
    //also can use fast slow pointer from LL (genius wow)
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;
            int count = 0;
            for (int num : nums) {
                if (num <= mid) ++count;
            }

            if (count > mid) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }
};
```
