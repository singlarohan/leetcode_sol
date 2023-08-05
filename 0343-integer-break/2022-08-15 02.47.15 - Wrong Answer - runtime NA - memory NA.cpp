class Solution {
public:
    int solve(int n, vector<int> &dp){
        if(n <= 0)
            return 1;
        if(dp[n] != -1)
            return dp[n];
        for(int i = 1; i<n; i++){
            dp[n] = max(dp[n], i * solve(n - 1, dp));
        }
        return dp[n];
    }
    int integerBreak(int n) {
        vector<int> dp(n+1, -1);
        int prod{1};
        for(int i = 1; i<n; i++){
            prod = max(prod, i*solve(n - i, dp));
        }
        return prod;
    }
};