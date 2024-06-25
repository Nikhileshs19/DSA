class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int l=0, r=0, pt=0, ans=0;
        unordered_map<int, int> ptMap;
        for(r=0;r<cardPoints.size();r++){
            pt += cardPoints[r];
            ptMap[r] = pt;
        }
        int total = pt;
        cout << total;
        r = cardPoints.size()-k-1;
        for(l=0;l<=k;l++){
            ans = max (ans, total - (ptMap[r]-ptMap[l-1]));
            cout << l << r << " " << ans << endl;
            r++;
        }
        return ans;
    }
};