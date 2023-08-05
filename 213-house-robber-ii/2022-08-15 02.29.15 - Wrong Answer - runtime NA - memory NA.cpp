class Solution {
public:
    int solve(int i, int ifTaken, vector<int> &dp, vector<int> &nums){
        if(ifTaken && i == nums.size() - 1)
            return 0;
        if(i>= nums.size())
            return 0;
        if(dp[i]!= -1)
            return dp[i];
        if(i == 0)
            ifTaken = 1;
        int choose = nums[i] + solve(i+2, ifTaken, dp, nums);
        ifTaken = 0;
        int notchoose = solve(i+1, ifTaken, dp, nums);
        return dp[i] = max(choose, notchoose);
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return solve(0, 0, dp, nums);
    }
};