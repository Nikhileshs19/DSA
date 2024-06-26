class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0, min = prices[0];
        for(int i=0;i<prices.size();i++){
            if(prices[i]<min)
                min = prices[i];
            if(prices[i] - min > ans)
                ans = prices[i] - min;
        }
        return ans;
    }
};