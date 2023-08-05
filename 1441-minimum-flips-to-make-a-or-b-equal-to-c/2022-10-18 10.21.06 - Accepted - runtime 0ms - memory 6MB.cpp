class Solution {
public:
    int minFlips(int a, int b, int c) {
        //adding ones to be flipped
        int count = __builtin_popcount((a | c) - c) + __builtin_popcount((b | c) - c);
        //zeroes to be flipped
        count += __builtin_popcount(c) - __builtin_popcount((a | b) & c);
        return count;
    }
};