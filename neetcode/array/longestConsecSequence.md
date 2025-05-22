Longest Consecutive Sequence
Solved
Given an array of integers nums, return the length of the longest consecutive sequence of elements that can be formed.

A consecutive sequence is a sequence of elements in which each element is exactly 1 greater than the previous element. The elements do not have to be consecutive in the original array.

You must write an algorithm that runs in O(n) time.

Example 1:

Input: nums = [2,20,4,10,3,4,5]

Output: 4
Explanation: The longest consecutive sequence is [2, 3, 4, 5].

Example 2:

Input: nums = [0,3,2,5,4,6,1,1]

Output: 7

```
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> set(nums.begin(), nums.end());
        int longest = 0;
        for(int num : set){
            if(set.find(num-1) == set.end()){
                int len = 1;
                while(set.find(num+len) != set.end()){
                    len++;
                }
                longest = max(longest,len);
            }

        }
        return longest;
    }
};
```
