class Solution {
public:
    int solve(int i, vector<int>& dp, vector<int>& nums){
        if(i >= nums.size() - 1)
            return 0;
        if(dp[i] != -1)
            return dp[i];
        int n = nums[i];
        int ans = INT_MAX;
        while(n--){
            ans = min(ans, solve(i + n + 1, dp, nums));
        }
        return dp[i] = 1 + ans;
    }
    
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, dp, nums);
    }
};