Best Time to Buy and Sell Stock
You are given an integer array prices where prices[i] is the price of NeetCoin on the ith day.

You may choose a single day to buy one NeetCoin and choose a different day in the future to sell it.

Return the maximum profit you can achieve. You may choose to not make any transactions, in which case the profit would be 0.

Example 1:

Input: prices = [10,1,5,6,7,1]

Output: 6
Explanation: Buy prices[1] and sell prices[4], profit = 7 - 1 = 6.

```
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l=0, r=1;
        int ans = 0;

        while(r<prices.size()){
            if(prices[l]<prices[r]){
                int profit = prices[r] - prices[l];
                ans = max(profit,ans);
            }
            else{
                l=r;
            }
            r++;
        }
        return ans;
    }
};
```
