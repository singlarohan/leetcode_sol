class Solution {
public:

    int solve(int n, vector<int> &dp){
        if(n < 0 )
            return 0;
        if(n == 0)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        return dp[n] = climbStairs(n-1) + climbStairs(n-2);
    }
    int climbStairs(int n) {
        vector<int> dp(n, -1);
        return solve(n, dp);
    }
};