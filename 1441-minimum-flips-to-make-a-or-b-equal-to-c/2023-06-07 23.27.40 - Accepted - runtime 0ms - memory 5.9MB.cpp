class Solution {
public:
    int minFlips(int a, int b, int c) {
        //number of set bits in a|c - c and b|c - c is our answer
        int ans = __builtin_popcount((a | c) - c) + __builtin_popcount((b | c) - c);
        ans += __builtin_popcount(c) - __builtin_popcount((a | b) & c);
        return ans;
    }
};