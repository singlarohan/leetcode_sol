class Solution {
public:
    int solve(int prev, int i, vector<int> &nums, vector<vector<int>> &dp){
        if(i >= nums.size())
            return 0;
        if(dp[i][prev + 1] != -1)
            return dp[i][prev + 1] ;
        int take = 0;
        int nottake = solve(prev, i + 1, nums, dp);
        if(prev == -1 || nums[prev] < nums[i])
            take = 1 + solve(i, i + 1, nums, dp);
        return dp[i][prev + 1] = max(take, nottake);
    }
    
    int lengthOfLIS(vector<int>& nums) {
        // vector<vector<int>> dp(nums.size(), vector<int> (nums.size() + 1 , -1));
        // return solve(-1,0, nums, dp);
        //TABULATION
        // vector<vector<int>> dp(nums.size() + 1, vector<int> (nums.size() + 1 , 0));
        // for(int i = nums.size() - 1; i >= 0; i--){
        //     for(int prev = i-1; prev >= -1; prev--){
        //         int nottake = dp[i+1][prev+1];
        //         int take = 0;
        //         if(prev == -1 || nums[prev] < nums[i])
        //             take = 1 + dp[i+1][i+1];
        //         dp[i][prev + 1] = max(take, nottake);
        //     }
        // }
        // return dp[0][-1+1];
        //TABULATION WITH SPACE OPTIMIZATION
        vector<int> next(nums.size() + 1, 0), curr(nums.size() + 1, 0);
        for(int i = nums.size() - 1; i >= 0; i--){
            for(int prev = i-1; prev >= -1; prev--){
                int nottake = next[prev+1];
                int take = 0;
                if(prev == -1 || nums[prev] < nums[i])
                    take = 1 + next[i+1];
                curr[prev + 1] = max(take, nottake);
            }
            next = curr;
        }
        return curr[-1+1];
        
    }
};