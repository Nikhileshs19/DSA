class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int l=0, last = nums[0];
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=last){
                last = nums[i];
                swap(nums[++l],nums[i]);
            }
        }
        return l+1;
    }
};