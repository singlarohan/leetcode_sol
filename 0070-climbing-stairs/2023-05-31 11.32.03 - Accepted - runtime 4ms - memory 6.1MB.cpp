class Solution {
public:
    int climbStairs(int n) {
        // vector<int> dp(n + 1, -1);
        // auto solve = [&](int i, auto &&self){
        //     if(i == n) return 1;
        //     if(i > n) return 0;
        //     if(dp[i] != -1) return dp[i];
        //     return dp[i] = self(i + 1, self) + self(i + 2, self);
        // };
        vector<int> dp(n + 2, -1);
        dp[n] = 1;
        dp[n + 1] = 0;
        for(int i = n - 1; i >= 0; i--){
            dp[i] = dp[i + 1] + dp[i + 2];
        }
        // return solve(0, solve);
        return dp[0];
    }
};