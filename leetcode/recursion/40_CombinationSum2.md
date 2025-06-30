40. Combination Sum II
    Solved
    Medium
    Topics
    premium lock icon
    Companies
    Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output:
[
[1,2,2],
[5]
]

```
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        sort(candidates.begin(),candidates.end());
        backtrack(0, candidates, current, result, target);
        return result;
    }

private:
    void backtrack(int start, vector<int>& candidates, vector<int>& current, vector<vector<int>>& result, int target) {
        if (target == 0) {
            result.push_back(current);
            return;
        }
        if (target < 0) return;

        for (int i = start; i < candidates.size(); ++i) {
            if (i > start && candidates[i] == candidates[i - 1]) continue;
            current.push_back(candidates[i]);
            backtrack(i+1, candidates, current, result, target - candidates[i]); // i, not i+1
            current.pop_back();
        }
    }
};
```
