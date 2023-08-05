class Solution {
public:

    
    int solve(int i, vector<int> & nums, int target, vector<vector<int>> &dp){
        if(target == 0)
            return 1;        
        if(target < 0 || i >= nums.size())
            return 0;
        if(dp[i][target]!= -1)
            return dp[i][target];
        int ans{0};
        for(int j = i; j<nums.size(); j++)
            ans += solve(i, nums, target - nums[j], dp);
        return dp[i][target] = ans;
    }
    
    int combinationSum4(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int> (target+1, -1));
        return solve(0, nums, target, dp);
    }
};