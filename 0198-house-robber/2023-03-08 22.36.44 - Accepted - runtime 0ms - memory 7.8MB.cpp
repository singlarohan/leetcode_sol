class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n, -1);
        auto solve = [&](int i, auto &&self){
            if(i >= n) return 0;
            if(dp[i] != -1) return dp[i];
            return dp[i] = max(nums[i] + self(i + 2, self), self(i + 1, self));
        };
        return solve(0, solve);
    }
};