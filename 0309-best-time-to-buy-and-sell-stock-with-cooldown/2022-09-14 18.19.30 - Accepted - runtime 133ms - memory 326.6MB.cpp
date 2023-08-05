class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(int i, vector<int> prices, int toBuy){
        if(i >= prices.size())
            return 0;
        if(dp[i][toBuy] != -1)
            return dp[i][toBuy];
        if(toBuy)
            return dp[i][toBuy] =  max(-prices[i] + solve(i + 1, prices, 0), solve(i+1, prices, 1));
        return dp[i][toBuy] = max(prices[i] + solve(i + 2, prices, 1), solve(i + 1, prices, 0));
    }
    
    int maxProfit(vector<int>& prices) {
        dp = vector<vector<int>> (prices.size(), vector<int> (2, -1));
        return solve(0, prices, 1);
    }
};