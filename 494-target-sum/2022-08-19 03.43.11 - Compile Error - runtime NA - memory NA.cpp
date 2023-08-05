class Solution {
public:
    vector<vector<int>> dp(21, vector<int>(1001, -1));
    int solve(int target, int i, vector<int> &nums, int &ans){
        if(target == 0 && i == nums.size())
            return 1;
        if(i >= nums.size())
            return 0;
        //inserting minus
        if(dp[i][target] != -1)
            return dp[i][target];
        int m = solve(target + nums[i], i+1, nums, ans);
        //inserting plus
        int p = solve(target - nums[i], i+1, nums, ans);
        return dp[i][target] = m+p;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        ans{};
        return solve(target, 0, nums, ans);
    }
};