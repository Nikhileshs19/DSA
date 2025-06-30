39. Combination Sum
    Solved
    Medium
    Topics
    premium lock icon
    Companies
    Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.

Example 1:

Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.
Example 2:

Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]
Example 3:

Input: candidates = [2], target = 1
Output: []

```
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;

        sort(candidates.begin(), candidates.end());  // Step 1: Sort to handle duplicates
        backtrack(0, candidates, current, result, target);
        return result;
    }
     void backtrack(int start, vector<int>& nums, vector<int>& current, vector<vector<int>>& ans, int target) {
        if (target == 0) {
            ans.push_back(current);
            return;
        }
        if (target < 0) return;

        for (int i = start; i < nums.size(); ++i) {
            // Step 2: Skip duplicates at the same recursive depth
            if (i > start && nums[i] == nums[i - 1]) continue;

            current.push_back(nums[i]);               // Choose
            backtrack(i, nums, current, ans, target-nums[i]);  // Explore
            current.pop_back();                       // Un-choose (backtrack)
        }
    }
};
```
