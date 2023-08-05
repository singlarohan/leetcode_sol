class Solution {
public:
    int solve(int ind, vector<int> &nums, vector<int> &dp){
        if(ind >= nums.size() -1)
            return 0;
        if(dp[ind] != -1)
            return dp[ind];     

        int jump = nums[ind];
        int ans = 1e9;
        for(int i=1; i<=jump; i++){
            int curr = 1 + solve(ind + i, nums, dp);
            ans = min(ans, curr);
        }
        return dp[ind] = ans;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1, -1);
        return solve(0, nums, dp);
    }
};