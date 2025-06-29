410. Split Array Largest Sum
     Solved
     Hard
     Topics
     premium lock icon
     Companies
     Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.

Return the minimized largest sum of the split.

A subarray is a contiguous part of the array.

Example 1:

Input: nums = [7,2,5,10,8], k = 2
Output: 18
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [7,2,5] and [10,8], where the largest sum among the two subarrays is only 18.
Example 2:

Input: nums = [1,2,3,4,5], k = 2
Output: 9
Explanation: There are four ways to split nums into two subarrays.
The best way is to split it into [1,2,3] and [4,5], where the largest sum among the two subarrays is only 9.

```
class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int l = *max_element(nums.begin(),nums.end()), r=accumulate(nums.begin(),nums.end(),0);
        int ans =r;
        while(l<=r){
            int m = l+(r-l)/2;
            if(possible(nums,k,m)){
                ans = m;
                r=m-1;
            }else{
                l = m+1;
            }

        }
        return ans;
    }

    bool possible(vector<int>&nums,int k,int sum){
        int count = 1;
        int cSum = 0;
        for(int num : nums){
            cSum += num;
            if(cSum > sum){
                count++;
                cSum = num;
                if(count > k ) return false;
            }
        }
        return true;
    }
};
```
