class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        // cout<<total;
        if(total % 2) return false;
        int target1 = total / 2;
        int n = nums.size();
        //after that this is just target sum
        vector<vector<int>> dp(n, vector<int> (target1 + 1, -1));
        auto solve = [&](int i, int target, auto &&self) -> bool{
            if(target == 0) return true;
            if(i >= n) return false;
            if(dp[i][target] != -1) return dp[i][target];
            
            bool ans = self(i + 1, target, self);

            if(target >= nums[i]) ans |= self(i + 1, target - nums[i], self);

            return dp[i][target] = ans;
        };
        return solve(0, target1, solve);
    }
};