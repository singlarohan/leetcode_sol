class Solution {
public:
    int solve(int i, vector<int> &dp, vector<int> &cost){
        if(i >= cost.size())
            return 0;
        if(dp[i] != -1)
            return dp[i];
        return dp[i] = cost[i] + min(solve(i+1, dp, cost), solve(i+2, dp, cost));
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(cost.size(), -1);
        // return min(solve(0, dp, cost), solve(1, dp, cost)); // memoization
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2; i < n; i++){
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
        }
        return min(dp[n-2], dp[n - 1]);
    }
};