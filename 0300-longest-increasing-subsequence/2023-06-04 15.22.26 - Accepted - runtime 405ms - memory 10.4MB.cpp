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
        // vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        // vector<int> next(n + 1, 0);
        // vector<int> curr(n + 1, 0);
        // // for(int j = 0; j<=n; j++) dp[n][j] = 0;
        // int ans{};
        // for(int i = n - 1; i >= 0; i--){
        //     for(int prev = i - 1; prev >= -1; prev--){
        //         // int nottake = dp[i+1][prev + 1];
        //         int nottake = next[prev + 1];
        //         int take = 0;
        //         if(prev == -1 || nums[i] > nums[prev])
        //         take = 1 + next[i + 1];
        //         curr[prev + 1] = max(take, nottake);
        //     }
        //     next = curr;
        // }
        // return curr[0];

        //Best version
        //DP stores the max sequence length till that index
        vector<int> dp(n + 1, 1);
        int maxi{1};
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] > nums[j])
                dp[i] = max(dp[i], 1 + dp[j]);
                maxi = max(dp[i], maxi);
            }
        }
        return maxi;
    }
};