class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
         int ans = 0;
      int j = 0;
      int n = nums.size();
      for(int i = 0; i < n; i++){
         if(nums[i] == 0) k--;
         while(j <= i && k <0){
            if(nums[j] == 0){
               k++;
            }
            j++;
         }
         ans = max(i - j + 1, ans);
      }
      return ans;
        
    }
};