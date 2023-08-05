class Solution {
public:
    int maxProduct(vector<int>& nums) {
        vector<int> dp(nums.size() + 1, INT_MIN);
        auto solve = [&](int i, auto &&self){
            if(i >= nums.size()) return 1;
            if(dp[i] != INT_MIN) return dp[i];

            return dp[i] = max(nums[i], nums[i] * self(i + 1, self));
        };
        return solve(0, solve);

    }
};