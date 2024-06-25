class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;

        // Step 1: Find a candidate
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
            }
            count += (num == candidate) ? 1 : -1;
        }

        // Step 2: Verify the candidate (optional)
        count = 0;
        for (int num : nums) {
            if (num == candidate) {
                count++;
            }
        }

        // Majority element is guaranteed to exist, so no need to check count
        return candidate;
    }
};
