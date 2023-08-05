class Solution {
public:
    int longestString(int x, int y, int z) {
        int ans{};
        ans += 2*min(x,y);
        ans += !(x == y);
        ans += z;
        
        return 2 * ans;
    }
};