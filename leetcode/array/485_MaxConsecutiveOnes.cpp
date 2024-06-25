class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxi = 0, num =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1)
                num++;
            else
                num = 0;
            maxi = max(num,maxi);
        }
        return maxi;
    }
};