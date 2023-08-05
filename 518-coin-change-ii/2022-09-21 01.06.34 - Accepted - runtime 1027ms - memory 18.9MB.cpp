class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(int i, int amount, vector<int> & coins){
        if(amount == 0)
            return 1;
        if(amount < 0)
            return 0;
        if(dp[i][amount] != -1)
            return dp[i][amount];
        int ans{};
        for(int j = i; j < coins.size(); j++)
            ans += solve(j, amount - coins[j], coins);
        return dp[i][amount] = ans;
    }
    
    int change(int amount, vector<int>& coins) {
        dp = vector<vector<int>> (coins.size(), vector<int> (amount + 1, -1));
        return solve(0, amount, coins);
    }
};