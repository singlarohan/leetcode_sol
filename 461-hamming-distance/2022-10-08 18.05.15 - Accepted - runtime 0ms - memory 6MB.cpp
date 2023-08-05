class Solution {
public:
    int hammingDistance(int x, int y) {
        // XOR and then popcount
        return __builtin_popcount(x^y);
        int count{};
        while(x || y){
            if(x % 2 != y % 2)
                count++;
            x = x >> 1;
            y = y >> 1;
        }
        // count += __builtin_popcount(x) + __builtin_popcount(y);
        return count;
    }
};