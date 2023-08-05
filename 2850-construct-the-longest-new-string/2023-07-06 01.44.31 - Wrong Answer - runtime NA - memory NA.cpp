class Solution {
public:
    int longestString(int x, int y, int z) {
        int ans{};
        ans += 2*min(x,y);
        if(z > abs(x - y)) ans += z + abs(x - y);
        else ans += 2 * z;
        
        return 2 * ans;
    }
};