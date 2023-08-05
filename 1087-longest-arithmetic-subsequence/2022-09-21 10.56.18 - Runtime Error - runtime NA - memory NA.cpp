class Solution {
public:
    vector<vector<vector<int>>> dp;
    vector<int> diff;
    int solve(int i, int prev, int d, vector<int> & nums){
        if(i >= nums.size())
            return 0;
        int ans{};
        if(dp[i][prev+1][d + 1] != -1)
            return dp[i][prev + 1][d + 1];
        for(int j = i; j < nums.size(); j++){
            if(prev == -1)
                ans = max(ans, 1 + solve(j+1, j, -1, nums));
            else if(d == -1){
                diff.push_back(nums[j] - nums[prev]);
                ans = max(ans, 1 + solve(j + 1, j, diff.size() - 1, nums));
            }
            else if(nums[j] - nums[prev] == diff[d])
                ans = max(ans, 1 + solve(j + 1, j, d, nums));
        }
        return dp[i][prev+1][d + 1] = ans;
    }
    
    int longestArithSeqLength(vector<int>& nums) {
        dp = vector<vector<vector<int>>> (nums.size(), vector<vector<int>> (nums.size() + 1, vector<int> (100, -1)));
        return solve(0, -1, -1, nums);
    }
    
};