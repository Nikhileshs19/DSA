Koko Eating Bananas
Solved
You are given an integer array piles where piles[i] is the number of bananas in the ith pile. You are also given an integer h, which represents the number of hours you have to eat all the bananas.

You may decide your bananas-per-hour eating rate of k. Each hour, you may choose a pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, you may finish eating the pile but you can not eat from another pile in the same hour.

Return the minimum integer k such that you can eat all the bananas within h hours.

Example 1:

Input: piles = [1,4,3,2], h = 9

Output: 2
Explanation: With an eating rate of 2, you can eat the bananas in 6 hours. With an eating rate of 1, you would need 10 hours to eat all the bananas (which exceeds h=9), thus the minimum eating rate is 2.

```
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        int ans = r;
        while(l<=r){
            int m = (l+r)/2;
            long long time = 0;
            for (int p : piles) {
                time += ceil(static_cast<double>(p) / m);
            }
            if(time<=h){
                ans=m;
                r = m-1;
            }
            else l=m+1;
        }
        return ans;
    }
};
```
