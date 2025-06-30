Code
Testcase
Test Result
Test Result 46. Permutations
Solved
Medium
Topics
premium lock icon
Companies
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:

Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:

Input: nums = [1]
Output: [[1]]

```
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        sort(nums.begin(),nums.end());
        rec(nums,ans,cur);
        return ans;
    }
    void rec(vector<int>&nums, vector<vector<int>> &ans, vector<int>&cur){
        if(cur.size() == nums.size())
            ans.push_back(cur);
        else{
            for(int i=0;i<nums.size();i++){
                if(find(cur.begin(),cur.end(),nums[i]) != cur.end() ) continue;
                cur.push_back(nums[i]);
                rec(nums,ans,cur);
                cur.pop_back();
            }
        }
    }
};
```
