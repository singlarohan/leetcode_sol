class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, -1);
        auto solve = [&](int rem, auto &&self){
            if(rem == 0) return 0;
            if(dp[rem] != -1) return dp[rem];
            int ans = 1e9;
            for(int i = 0; i < coins.size(); i++)
                if(coins[i] <= rem) ans = min(ans, 1 + self(rem - coins[i], self));
            return dp[rem] = ans;
        };
        int ans = solve(amount, solve);
        return ans >= 1e9 ? -1 : ans;
    }
};