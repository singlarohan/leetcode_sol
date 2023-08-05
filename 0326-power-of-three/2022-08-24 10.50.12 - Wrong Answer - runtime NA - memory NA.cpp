class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0)
            return false;
       float i = log2(n)/log2(3);
        if(i-(int)i == 0)
            return true;
        return false;
    }
};