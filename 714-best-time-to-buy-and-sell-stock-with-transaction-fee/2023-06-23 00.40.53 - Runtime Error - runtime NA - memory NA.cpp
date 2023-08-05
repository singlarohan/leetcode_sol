class Solution {
private:
    vector<int> dp;
public:
    int solve(int i, vector<int> &prices, int fee){
        if(i >= prices.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int ans{};
        for(int j = i + 1; j <= prices.size(); j++){
            if(prices[j] - prices[i] > fee)
                ans = max(ans, prices[j] - prices[i] - fee + solve(j + 1, prices, fee));
        }
        return dp[i] = ans;
    }

    int maxProfit(vector<int>& prices, int fee) {
        //using dp
        dp = vector<int> (prices.size(), -1);
        return solve(0, prices, fee);
    }
};