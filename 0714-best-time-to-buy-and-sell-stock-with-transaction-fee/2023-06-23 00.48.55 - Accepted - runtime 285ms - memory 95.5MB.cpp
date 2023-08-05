class Solution {
private:
    vector<vector<int>> dp;
public:
    int solve(int i, bool toBuy, vector<int> &prices, int fee){
        if(i >= prices.size()) return 0;
        
        if(dp[i][toBuy] != -1) return dp[i][toBuy];

        int ans = solve(i + 1, toBuy, prices, fee);

        if(toBuy) ans = max(ans, -prices[i] + solve(i + 1, !toBuy, prices, fee));
        else ans = max(ans, prices[i] - fee + solve(i + 1, !toBuy, prices, fee));
        
        return dp[i][toBuy] = ans;
    }

    int maxProfit(vector<int>& prices, int fee) {
        //using dp
        dp = vector<vector<int>> (prices.size(), vector<int> (2, -1));
        return solve(0, 1, prices, fee);
    }
};