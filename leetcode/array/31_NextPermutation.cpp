class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;
        
        // Step 1: Find the first decreasing element
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }
        
        if (i >= 0) { // If such element was found
            // Step 2: Find the element just larger than nums[i]
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            // Step 3: Swap the elements
            swap(nums[i], nums[j]);
        }
        
        // Step 4: Reverse the elements from i + 1 to the end
        reverse(nums.begin() + i + 1, nums.end());
    }
};