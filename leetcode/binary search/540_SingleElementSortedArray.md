540. Single Element in a Sorted Array
     Solved
     Medium
     Topics
     premium lock icon
     Companies
     You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly once.

Return the single element that appears only once.

Your solution must run in O(log n) time and O(1) space.

Example 1:

Input: nums = [1,1,2,3,3,4,4,8,8]
Output: 2
Example 2:

Input: nums = [3,3,7,7,10,11,11]
Output: 10

```
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int l = 0, r = nums.size() - 1; // Corrected here
        int ans = -1;
        while (l < r) {
            int m = l + (r - l) / 2;
            if(m%2==1) m--;
            if(nums[m]!=nums[m+1]){
                r = m;
            }
            else{
                l=m+2;
            }

        }
        return nums[l];
    }
};
```
