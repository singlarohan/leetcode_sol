class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        //memoization
        // vector<int> dp (n, -1);
        // auto solve = [&](int i, auto &&self){
        //     if(i >= n) return 0;
        //     if(dp[i] != -1) return dp[i];
        //     return dp[i] = max(nums[i] + self(i + 2, self), self(i + 1, self));
        // };
        // return solve(0, solve);
        
        //Tabulation
        vector<int> dp(n + 2, -1);
        dp[n] = 0, dp[n + 1] = 0;
        for(int i = n - 1; i >= 0; i--){
            dp[i] = max(nums[i] + dp[i + 2], dp[i + 1]);
        }
        return dp[0];
    }
};