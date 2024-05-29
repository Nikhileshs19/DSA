class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int max_num = *max_element(candies.begin(), candies.end()); 
        vector<bool> a(candies.size());
        for(int i = 0; i < candies.size(); i++) {
            a[i] = (candies[i] + extraCandies >= max_num);
        }
        return a;
    }
};

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxCandies = 0;
        for (int candy : candies) {
            maxCandies = max(maxCandies, candy);
        }
        // For each kid, check if they will have greatest number of candies
        // among all the kids.
        vector<bool> result;
        for (int candy : candies) {
            result.push_back(candy + extraCandies >= maxCandies);
        }

        return result;
    
    }
};


