class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n == 0)
            return 0;
        if(n < 0)
            return INT_MAX - 100000;
        if(dp[n] != -1)
            return dp[n];
        int ans{INT_MAX - 100000};
        for(int j = 1; j <= sqrt(n); j++)
            ans = min(ans, 1 + solve(n - j*j, dp));
        return dp[n] = ans;
    }
    int numSquares(int n) {
        // vector<vector<int>> dp(n + 1, vector<int> (n , -1));
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};