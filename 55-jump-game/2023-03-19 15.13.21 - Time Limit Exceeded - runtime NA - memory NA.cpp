class Solution {
public:
    int dp[(int)1e5+10];
    
    bool solve(int i, vector<int> &nums){
        if(i >= nums.size() - 1)
            return true;
        if(dp[i]!= -1)
            return dp[i];
        dp[i] = 0;
        for(int j = 1; j <= nums[i]; j++){
            dp[i] = dp[i] || solve(i+j, nums);
        }
        return dp[i];
    }
    
    bool canJump(vector<int>& nums) {
        // memset(dp, -1, sizeof(dp));
        memset(dp, 0, sizeof(dp));
        int n = nums.size();
        dp[n - 1] = true;
        // return solve(0, nums);
        for(int i = n - 2; i >= 0; i--){
            // dp[i] = 0;
            for(int j = 1; j <= nums[i]; j++){
                dp[i] = dp[i] || dp[i+j];
            }
            // return dp[i];
        }
        return dp[0];
    }
};
