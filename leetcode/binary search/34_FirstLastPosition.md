34. Find First and Last Position of Element in Sorted Array
    Solved
    Medium
    Topics
    premium lock icon
    Companies
    Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

```
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1,-1};
        res[0] = binaryS(nums,target,true);
        res[1] = binaryS(nums,target,false);
        return res;
    }
    int binaryS(vector<int>&nums, int target, bool left){
        int n = nums.size();
        int l = 0, r = n-1;
        int ans = -1;
        while(l<=r){
            int m = (l+r)/2;
            if(target> nums[m]) l=m+1;
            else if(target < nums[m]) r = m-1;
            else{
                ans = m;
                if(left){
                    r = m - 1;
                }
                else l = m+1;
            }
        }
        return ans;
    }
};
```
