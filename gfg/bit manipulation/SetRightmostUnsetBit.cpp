class Solution {
  public:
    int setBit(int n) {
        // Write Your Code here
        int i = 1;
        while(n&i){
            i *= 2;
        }
        n += i;
        return n;
    }
};