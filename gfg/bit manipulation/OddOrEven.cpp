class Solution
{
    public:
    // Function to check if Kth bit is set or not.
    bool checkKthBit(int n, int k)
    {
        return n&(int)pow(2,k)?1 : 0;
    }
};