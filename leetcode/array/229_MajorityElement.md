229. Majority Element II
     Solved
     Medium
     Topics
     premium lock icon
     Companies
     Hint
     Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

Example 1:

Input: nums = [3,2,3]
Output: [3]
Example 2:

Input: nums = [1]
Output: [1]
Example 3:

Input: nums = [1,2]
Output: [1,2]

```
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> count;
        for(int i=0;i<nums.size();i++){
            if(count.find(nums[i]) != count.end())
                count[nums[i]]++;
            else
                count[nums[i]] = 1;
        }
        for(const auto& [key,c] : count){
            if(c > nums.size()/3)
                ans.push_back(key);
        }
        return ans;
    }
};
```
