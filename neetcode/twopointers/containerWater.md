Container With Most Water
Solved
You are given an integer array heights where heights[i] represents the height of the ith bar.

You may choose any two bars to form a container. Return the maximum amount of water a container can store.

Example 1:

Input: height = [1,7,2,5,4,7,3,6]

Output: 36

```
class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l=0,r=n-1;
        int ans = 0;

        while(l<r){
            int area = min(heights[l],heights[r])*(r-l);
            ans = max(ans,area);

            if(heights[l]<=heights[r])
                l++;
            else
                r--;

        }
        return ans;
    }
};
```
