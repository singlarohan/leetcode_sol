class Solution {
public:

    int solve(int target, int i, vector<int> &nums, vector<vector<int>> &dp){
        if(target == 0 && i == nums.size())
            return 1;
        if(i >= nums.size())
            return 0;
        //inserting minus
        if(dp[i][target+1001] != -1)
            return dp[i][target+1001];
        int m = solve(target + nums[i], i+1, nums, dp);
        //inserting plus
        int p = solve(target - nums[i], i+1, nums, dp);
        return dp[i][target+1001] = m+p;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int> (3000, -1));
        return solve(target, 0, nums, dp);
    }
};