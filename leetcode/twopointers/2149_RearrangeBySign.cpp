class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> even;
        vector<int> odd;
        vector<int> res;

        for (auto value:nums){
            
            if (value > 0){
                odd.push_back(value);
            }
            else{
                even.push_back(value);
            }
            
        }

        for (int i = 0 ; i < odd.size() ; i++){
            res.push_back(odd[i]);
            res.push_back(even[i]);
        }

        return res;
    }
};