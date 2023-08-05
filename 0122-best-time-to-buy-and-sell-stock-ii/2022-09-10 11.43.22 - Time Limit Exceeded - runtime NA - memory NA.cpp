class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(int i, int toBuy, vector<int> &prices){
        if(i >= prices.size())
            return 0;
        if(dp[i][toBuy] != -1)
            return dp[i][toBuy];
        if(toBuy)
            return max(-prices[i] + solve(i+1, 0, prices), solve(i+1, 1, prices));
        else
            return max(prices[i] + solve(i+1, 1, prices), solve(i+1, 0, prices));
    }
    
    int maxProfit(vector<int>& prices) {
        //Greedy
        // int profit{};
        // for(int i = 1; i<prices.size(); i++){
        //     if(prices[i-1]<prices[i]){
        //         profit += prices[i] - prices[i-1];
        //     }
        // }
        // return profit;
        
        //Dynamic Prog
        dp = vector<vector<int>> (prices.size() , vector<int> (2, -1));
        return solve(0, 1, prices);
    }

};