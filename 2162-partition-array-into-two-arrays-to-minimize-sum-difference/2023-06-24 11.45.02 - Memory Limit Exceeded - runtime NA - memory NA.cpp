class Solution {
private:
    vector<vector<int>> dp;
    int n;
public:
    int solve(int i, int mask, int curr, const int total, vector<int> &nums){
        int k = __builtin_popcount(mask);
        
        if(k == n / 2) return abs(total - curr);
        if(i >= nums.size() || i + (n/2 - k) - 1 > n) return 1e9;
        
        if(dp[i][mask] != -1) return dp[i][mask];
        //not choose
        int ans = solve(i + 1, mask, curr, total, nums);
        
        //choose
        ans = min(ans, 
                    solve(i + 1, mask | (1 << i), curr + nums[i], total - nums[i], nums));

        return dp[i][mask] = ans;

    }

    int minimumDifference(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        n = nums.size();
        
        dp = vector<vector<int>> (n, vector<int> (1 << n, -1));

        return solve(0, 0, 0, sum, nums);
    }
};