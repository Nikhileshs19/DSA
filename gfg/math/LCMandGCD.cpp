class Solution {
  public:
  
  int findGcd(long long a, long long b) {
    while(a > 0 && b > 0) {
        if(a > b)
            a = a % b;
        else 
            b = b % a; 
    }
    if(a == 0) 
        return b;
    return a;
}

    vector<long long> lcmAndGcd(long long A , long long B) {
        long long gcd = findGcd(A,B);
        long long lcm = (A*B)/gcd;
        vector<long long> ans;
        ans.push_back(lcm);
        ans.push_back(gcd);
        return ans;
    }
};