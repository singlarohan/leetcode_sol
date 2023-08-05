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
        // vector<int> dp(cost.size(), -1);
        // return min(solve(0, dp, cost), solve(1, dp, cost)); // memoization
        int temp1 = cost[0];
        int temp2 = cost[1];
        for(int i = 2; i < n; i++){
            int curr = temp2;
            temp2 = cost[i] + min(temp1, temp2);
            temp1 = curr;
                
        }
        return min(temp1, temp2);
    }
};