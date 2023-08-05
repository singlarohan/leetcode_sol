class Solution {
public:
    int solve(int i, bool ifTaken, vector<int> &dp, vector<int> &nums){
        if(ifTaken && i == nums.size() - 1 || i>= nums.size())
            return 0;
        if(dp[i]!= -1)
            return dp[i];
        int choose = nums[i] + solve(i+2, ifTaken, dp, nums);
        int notchoose = solve(i+1, ifTaken, dp, nums);
        return dp[i] = max(choose, notchoose);
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        vector<int> dp1(nums.size(), -1);
        return max(solve(1, 0, dp, nums), solve(0,1,dp1,nums));
    }
};