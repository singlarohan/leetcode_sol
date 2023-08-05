class Solution {
public:
    bool isPowerOfFour(int n) {
        if(pow(4, log2(n) / 2) == n)
            return true;
        return false;
    }
};