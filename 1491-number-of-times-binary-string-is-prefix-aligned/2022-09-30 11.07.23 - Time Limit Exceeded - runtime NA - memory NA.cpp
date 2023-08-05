class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        vector<bool> dp(flips.size(), false);
        vector<bool> flipped(flips.size(), false);
        auto check = [&](int i, auto && self){
            if(i == 0) return dp[0] = flipped[0];
            if(dp[i] != false) return dp[i];
            return dp[i] = flipped[i] && self(i - 1, self);
        };
        int count{};
        for(int i = 0; i < flips.size(); i++){
            flipped[flips[i] - 1] = true;
            if(check(i, check))
                count++;
        }
        return count;
    }
};