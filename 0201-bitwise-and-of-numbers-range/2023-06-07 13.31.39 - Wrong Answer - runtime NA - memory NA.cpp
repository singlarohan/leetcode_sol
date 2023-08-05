class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        return left & right &((long long)left + right) /2;
    }
};