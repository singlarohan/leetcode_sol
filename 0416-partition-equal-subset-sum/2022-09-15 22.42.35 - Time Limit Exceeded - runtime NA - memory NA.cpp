class Solution {
public:
    // vector<vector<vector<int>>> dp;
    bool solve(vector<int> &nums, int i, int s1, int s2){
        if(i >= nums.size())
            return s1 == s2;
        // if(dp[i][s1][s2] != -1)
        //     return dp[i][s1][s2];
        //if choose current in 1st subset or in 2nd
        return solve(nums, i + 1, s1 + nums[i], s2) || solve(nums, i + 1, s1, s2 + nums[i]);
    }
    
    bool canPartition(vector<int>& nums) {
        // dp = vector<vector<vector<int>>> (nums.size(), vector<vector<int>> (2000, vector<int> (2000, -1)));
        return solve(nums, 0, 0, 0);
    }
};