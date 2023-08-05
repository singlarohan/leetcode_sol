class Solution {
public:
    bool solve(int i, vector<int> &nums, vector<int> &dp){
        if(i>= nums.size() || (i != nums.size() - 1 && nums[i] == 0))
            return false;
        if(i == nums.size() - 1)
            return true;
        if(dp[i]!= -1)
            return dp[i];
        bool ans = false;
        for(int j = 1; j<= nums[i]; j++){
            ans = ans || solve(i+j, nums, dp);
        }
        return dp[i] = ans;
    }
    
    bool canJump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, nums, dp);
    }
};