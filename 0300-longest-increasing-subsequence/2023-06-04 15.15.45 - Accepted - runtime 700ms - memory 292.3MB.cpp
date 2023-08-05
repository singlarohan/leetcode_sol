class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        // auto solve = [&](int i, int prev, auto &&self){
        //     if(i >= n) return 0;
        //     if(dp[i][prev + 1] != -1) return dp[i][prev + 1];
        //     int ans{};
        //     if(prev == -1 || nums[i] > nums[prev])
        //     ans = 1 + self(i + 1, i, self);
        //     ans = max(ans, self(i + 1, prev, self));
        //     return dp[i][prev + 1] = ans; 
        // };
        // return solve(0, -1, solve);
        //TABULATION OF THIS
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        for(int j = 0; j<=n; j++) dp[n][j] = 0;
        int ans{};
        for(int i = n - 1; i >= 0; i--){
            for(int prev = i - 1; prev >= -1; prev--){
                int nottake = dp[i+1][prev + 1];
                int take = 0;
                if(prev == -1 || nums[i] > nums[prev])
                take = 1 + dp[i+1][i + 1];
                dp[i][prev + 1] = max(take, nottake);
            }
        }
        return dp[0][0];
    }
};