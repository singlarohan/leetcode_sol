class Solution {
private:
    vector<vector<long long>> dp;
    int n;
public:
    long long solve(bool parity, int i, vector<int> &nums, int x){
        if(i >= n) return 0;
        
        if(dp[i][parity] != -1) return dp[i][parity];
        
        long long ans = 0;
        
        if(nums[i] % 2 == parity) ans = nums[i] + solve(parity, i + 1, nums, x);
        else {
            ans = solve(parity, i + 1, nums, x);
            ans = max(ans, -x + nums[i] + solve(!parity, i + 1, nums, x));
        }
        
        return dp[i][parity] = ans;
    }
    long long maxScore(vector<int>& nums, int x) {
        n = nums.size();
        dp = vector<vector<long long>> (n, vector<long long> (2, -1));
        return max(solve(0, 0, nums, x), solve(1, 0, nums, x));
    }
};