class Solution {
public:
    vector<vector<vector<int>>> dp;
    int solve(int i, int prev, int d, vector<int> & nums){
        if(i >= nums.size())
            return 0;
        int ans{};
        if(dp[i][prev+1][d + 501] != -1)
            return dp[i][prev + 1][d + 501];
        for(int j = i; j < nums.size(); j++){
            if(prev == -1)
                ans = max(ans, 1 + solve(j+1, j, -501, nums));
            else if(d == -501)
                ans = max(ans, 1 + solve(j + 1, j, nums[j] - nums[prev], nums));
            else if(nums[j] - nums[prev] == d)
                ans = max(ans, 1 + solve(j + 1, j, d, nums));
        }
        return dp[i][prev+1][d + 501] = ans;
    }
    
    int longestArithSeqLength(vector<int>& nums) {
        dp = vector<vector<vector<int>>> (nums.size(), vector<vector<int>> (nums.size() + 1, vector<int> (1002, -1)));
        return solve(0, -1, -501, nums);
    }
    
};

 