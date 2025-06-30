90. Subsets II
    Solved
    Medium
    Topics
    premium lock icon
    Companies
    Given an integer array nums that may contain duplicates, return all possible subsets (the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

Example 1:

Input: nums = [1,2,2]
Output: [[],[1],[1,2],[1,2,2],[2],[2,2]]
Example 2:

Input: nums = [0]
Output: [[],[0]]

```
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(nums.begin(),nums.end());
        backtrack(0,nums,cur,ans);
        return ans;
    }
    void backtrack(int start, vector<int>&nums,vector<int>& cur, vector<vector<int>>& ans){
        ans.push_back(cur);
        for(int i = start;i<nums.size();++i){
            if(i>start && nums[i] == nums[i-1]) continue;
            cur.push_back(nums[i]);
            backtrack(i+1,nums,cur,ans);
            cur.pop_back();
        }
    }
};
```
