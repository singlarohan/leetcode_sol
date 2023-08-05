class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 0)
            return false;
        int i = log2(n) / 2;
        if(pow(4, i) == n)
            return true;
        return false;
    }
};