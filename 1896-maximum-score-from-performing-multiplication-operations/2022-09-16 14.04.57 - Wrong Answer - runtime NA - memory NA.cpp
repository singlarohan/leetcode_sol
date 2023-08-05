class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(vector<int> & nums, vector<int> &mul, int i, int j){
        if(i + j >= mul.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = max(nums[i] * mul[i+j] + solve(nums, mul, i+1, j), nums[nums.size() - j - 1] * mul[i+j] + solve(nums, mul, i, j+1));
    }

    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        // i distance from the beginning
        // j distance from end
        dp = vector<vector<int>> (nums.size(), vector<int> (nums.size(), INT_MIN));
        return solve(nums, multipliers, 0, 0);
    }
};