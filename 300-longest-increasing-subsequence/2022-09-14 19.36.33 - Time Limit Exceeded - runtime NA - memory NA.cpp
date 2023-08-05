class Solution {
public:
    int solve(int prev, int i, vector<int> &nums, vector<int> &dp){
        if(i >= nums.size())
            return 0;
        int take = 0;
        int nottake = solve(prev, i + 1, nums, dp);
        if(prev == -1 || nums[prev] < nums[i])
            take = 1 + solve(i, i + 1, nums, dp);
        return max(take, nottake);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, -1);
        return solve(-1,0, nums, dp);
    }
};