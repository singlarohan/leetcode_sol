class Solution {
public:
    int countOdds(int low, int high) {
        int ans = (high - low)/2;
        if((high % 2 != 0) || (low % 2 != 0)) ans += 1;
        return ans;
    }
};