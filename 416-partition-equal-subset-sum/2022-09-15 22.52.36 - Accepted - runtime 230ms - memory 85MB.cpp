class Solution {
public:
    vector<vector<int>> dp;
    bool solve(vector<int> &nums, int i, int target){
        if(target == 0)
            return true;
        if(i >= nums.size() || target < 0)
            return false;
        if(dp[i][target] != -1)
            return dp[i][target];
        return dp[i][target] = solve(nums, i+1, target - nums[i]) || solve(nums, i+1, target);
    }
    
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(total % 2 != 0)
            return false;
        int target = total/2;
        dp = vector<vector<int>> (nums.size(), vector<int> (target + 1, -1));
        return solve(nums, 0, target);
    }
};