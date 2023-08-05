class Solution {
private:
    // vector<vector<int>> dp;
public:
    // int solve(int i, bool toBuy, vector<int> &prices, int fee){
    //     if(i >= prices.size()) return 0;
        
    //     if(dp[i][toBuy] != -1) return dp[i][toBuy];

    //     int ans = solve(i + 1, toBuy, prices, fee);

    //     if(toBuy) ans = max(ans, -prices[i] + solve(i + 1, !toBuy, prices, fee));
    //     else ans = max(ans, prices[i] - fee + solve(i + 1, !toBuy, prices, fee));
        
    //     return dp[i][toBuy] = ans;
    // }

    int maxProfit(vector<int>& prices, int fee) {
        //using dp
        // dp = vector<vector<int>> (prices.size(), vector<int> (2, -1));
        // return solve(0, 1, prices, fee);
        
        int n = prices.size();
        // vector<vector<int>> dp(n + 1, vector<int> (2, 0));
        
        vector<int> next(2, 0);
        vector<int> curr(2, 0);

        for(int i = n - 1; i >= 0; i--){
            for(int toBuy = 1; toBuy >= 0; toBuy--){
                int ans = next[toBuy];

                if(toBuy) ans = max(ans, -prices[i] + next[!toBuy]);
                else ans = max(ans, prices[i] - fee + next[!toBuy]);
                
                curr[toBuy] = ans;
            }
            next = curr;
        }
        return curr[1];
    }
};