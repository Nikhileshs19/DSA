class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_so_far = nums[0];
        int max_ending_here = nums[0];
        
        for (size_t i = 1; i < nums.size(); ++i) {
            max_ending_here = max(nums[i], max_ending_here + nums[i]);
            max_so_far = max(max_so_far, max_ending_here);
        }
        
        return max_so_far;
    }
};