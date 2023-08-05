class Solution {
public:
    int solve(int amount, vector<int> &coins, vector<int> &dp){
        if(amount == 0)
            return 0;
        if(amount < 0)
            return INT_MAX-1;
        if(dp[amount] != -1)
            return dp[amount];
        int ans{INT_MAX-1};
        for(int i = 0; i < coins.size(); i++){
            ans = min(ans, solve(amount - coins[i], coins, dp));
        }
        return dp[amount] = 1 + ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1, -1);
        int ans = solve(amount, coins, dp);
        if(ans == INT_MAX)
            return -1;
        else
            return ans;
    }
};