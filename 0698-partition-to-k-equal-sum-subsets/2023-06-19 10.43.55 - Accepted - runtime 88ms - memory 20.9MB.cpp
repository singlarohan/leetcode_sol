class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);
        // cout<<total<<endl;
        if(total % k != 0) return 0;
        int target = total / k;
        // cout<<target<<endl;
        vector<int> dp(1 << n, -1);
        auto solve = [&](int mask, int curr, auto &&self) -> bool{
            if(curr == total) return true;
            if(dp[mask] != -1) return dp[mask];
            bool ans = false;
            for(int i = 0; i < n; i++){
                if((mask & (1 << i)) == 0){
                    if((curr % target) + nums[i] <= target)
                        ans |= self(mask | (1 << i), curr + nums[i], self);
                }
                // cout<<mask<<" "<<curr<<" "<<i<<" "<<ans<<endl;
                if(ans) break;
            }
            return dp[mask] = ans;
        };
        return solve(0, 0, solve);
    }
};