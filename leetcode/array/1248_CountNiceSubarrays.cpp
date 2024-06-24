class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        countMap[0] = 1; // To handle cases where the number of odd numbers so far is exactly k.
        int count = 0, oddCount = 0, result = 0;

        for (int num : nums) {
            if (num % 2 != 0) {
                oddCount++;
            }

            if (countMap.find(oddCount - k) != countMap.end()) {
                result += countMap[oddCount - k];
            }

            countMap[oddCount]++;
        }

        return result;
    }
};