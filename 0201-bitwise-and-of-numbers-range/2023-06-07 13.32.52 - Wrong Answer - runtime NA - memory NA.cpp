class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == right) return left;
        return left & right & ((long long)left + right) /2 & ((long long)left + right)/2 + 1;
    }
};