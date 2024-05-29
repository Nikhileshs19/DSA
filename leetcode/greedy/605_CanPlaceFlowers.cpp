class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        for (int i = 0; i < flowerbed.size(); i++) {
            // Check if the current plot is empty.
            if (flowerbed[i] == 0) {
                // Check if the left and right plots are empty.
                bool emptyLeftPlot = (i == 0) || (flowerbed[i - 1] == 0);
                bool emptyRightPlot = (i == flowerbed.size() - 1) || (flowerbed[i + 1] == 0);
                
                // If both plots are empty, we can plant a flower here.
                if (emptyLeftPlot && emptyRightPlot) {
                    flowerbed[i] = 1;
                    count++;
                    if (count >= n) {
                        return true;
                    }
                }
            }
        }
        return count >= n;
    }
};


class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int num = 0;
        if(flowerbed.size()==1){
            if(flowerbed[0]==1 && n==1)
                return 0;
                return 1;
        }
            
        if(flowerbed[0]==0 && flowerbed[1]==0){
            flowerbed[0]=1;
            num++;
        }
        for(int i=2;i<flowerbed.size()-1;i++){
            if(flowerbed[i]==1)
                continue;
            if(flowerbed[i-1]==0 && flowerbed[i+1]==0){
                flowerbed[i]=1;
                num++;
            }
            
        }
        if(flowerbed[flowerbed.size()-1]==0 && flowerbed[flowerbed.size()-2] == 0)
                num++;
        cout << num;
        if(num < n)
            return 0;
        else 
            return 1;
    }
};