Trapping Rain Water
Solved
You are given an array non-negative integers height which represent an elevation map. Each value height[i] represents the height of a bar, which has a width of 1.

Return the maximum area of water that can be trapped between the bars.

Example 1:

Input: height = [0,2,0,3,1,0,1,3,2,1]

Output: 9

```
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n-1;
        int leftm = height[l], rightm = height[r];
        int ans = 0;
        while(l<r){
            if(leftm < rightm){
                l++;
                leftm = max(leftm,height[l]);
                ans += leftm - height[l];
            }
            else{
                r--;
                rightm = max(rightm,height[r]);
                ans+= rightm-height[r];
            }
        }

        return ans;

    }
};
```

```
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) {
            return 0;
        }

        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0] = height[0];
        for (int i = 1; i < n; i++) {
            leftMax[i] = max(leftMax[i - 1], height[i]);
        }

        rightMax[n - 1] = height[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i]);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res += min(leftMax[i], rightMax[i]) - height[i];
        }
        return res;
    }
};
```
