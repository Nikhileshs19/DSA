class Solution {
public:
    int minBitFlips(int start, int goal) {
        int diff = goal ^ start;
        int ans = 0;
        while(diff){
            ans += diff & 1;
            diff >>= 1;
        }
        return ans;
    }
};