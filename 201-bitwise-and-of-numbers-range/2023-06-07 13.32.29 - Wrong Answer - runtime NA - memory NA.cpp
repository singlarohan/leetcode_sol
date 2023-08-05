class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        return left & right & ((long long)left + right) /2 & ((long long)left + right)/2 + 1;
    }
};