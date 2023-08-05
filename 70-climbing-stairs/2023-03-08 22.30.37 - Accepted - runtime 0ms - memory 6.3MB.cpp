class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, -1);
        auto solve = [&](int i, auto &&self){
            if(i == n) return 1;
            if(i > n) return 0;
            if(dp[i] != -1) return dp[i];
            return dp[i] = self(i + 1, self) + self(i + 2, self);
        };
        return solve(0, solve);
    }
};