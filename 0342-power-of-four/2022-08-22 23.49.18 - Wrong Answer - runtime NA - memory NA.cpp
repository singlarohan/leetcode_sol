class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 0)
            return false;
        if(pow(4, log2(n) / 2) == n)
            return true;
        return false;
    }
};