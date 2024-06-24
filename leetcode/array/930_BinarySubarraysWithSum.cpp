class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        unordered_map<int, int> countMap;
        countMap[0] = 1; // Initialize with a base case where the cumulative sum is 0.
        int ans = 0, s = 0;
        for (int& v : nums) {
            s += v;
            if (countMap.find(s - goal) != countMap.end()) {
                ans += countMap[s - goal];
            }
            ++countMap[s];
        }
        return ans;
    }
};