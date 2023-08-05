class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int> (3, -1));
        auto function = [&](int i, int rem, auto &&self) -> int{
            if(rem == 0 && i >= nums.size())
                return 0;
            if(i >= nums.size())
                return INT_MIN;
            if(dp[i][rem] != -1)
                return dp[i][rem];
            //choose
            int a = nums[i] + self(i + 1, (rem + nums[i]) % 3, self);
            //not choose
            int b = self(i + 1, rem, self);
            return dp[i][rem] = max(a,b);
        };
        return function(0, 0, function);
    }
};