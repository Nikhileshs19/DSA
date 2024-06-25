class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> map;
        for(int i=0;i<nums.size();i++){
            int j = target - nums[i];
            if(map.find(j)!=map.end())
                return {map[j],i};
            else
                map[nums[i]]=i;
        }
        return {0};
    }
};