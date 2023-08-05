class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp (high + max(one, zero) + 1, 0);
        int M = 1e9 + 7;
        //TABULATION

        for(int curr = high; curr >= 0; curr--){
            long long ans = curr >= low && curr <= high;
            ans += dp[curr + one];
            ans += dp[curr + zero];
            dp[curr] = ans % M;
        }
        return dp[0];
    }
};