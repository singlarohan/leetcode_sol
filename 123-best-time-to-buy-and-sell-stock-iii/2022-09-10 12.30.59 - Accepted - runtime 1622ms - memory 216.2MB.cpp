class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(int i, vector<int> &prices, int toBuy, int count){
        if(i >= prices.size() || count == 0)
            return 0;
        if(dp[i][toBuy][count - 1] != -1) return dp[i][toBuy][count - 1];
        if(toBuy)
            return dp[i][toBuy][count - 1] = max(-prices[i] + solve(i + 1, prices, 0, count), solve(i + 1, prices, 1, count));
        else
            return dp[i][toBuy][count - 1] = max(prices[i] + solve(i + 1, prices, 1, count - 1), solve(i + 1, prices, 0, count));
    }
    
    int maxProfit(vector<int>& prices) {
        dp = vector<vector<vector<int>>> (prices.size(), vector<vector<int>> (2, vector<int> (2, -1)));
        return solve(0, prices, 1, 2);
    }
};