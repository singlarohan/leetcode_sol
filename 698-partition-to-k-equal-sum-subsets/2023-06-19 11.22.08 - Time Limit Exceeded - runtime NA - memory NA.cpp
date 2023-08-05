class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        int total = accumulate(nums.begin(), nums.end(), 0);

        if(total % k != 0) return 0;
        int target = total / k;
        // vector<int> dp(1 << n, -1);
        // auto solve = [&](int mask, int curr, auto &&self) -> bool{
        //     if(curr + target == total) return true;
        //     if(dp[mask] != -1) return dp[mask];
        //     bool ans = false;
        //     for(int i = 0; i < n; i++){
        //         if((mask & (1 << i)) == 0){
        //             if((curr % target) + nums[i] <= target)
        //                 ans |= self(mask | (1 << i), curr + nums[i], self);
        //         }
        //         if(ans) break;
        //     }
        //     return dp[mask] = ans;
        // };

        //Method 2 - Backtracking
        vector<int> vis(n, 0);
        auto backtrack = [&](int i, int curr, auto &&self) -> bool{
            if(curr == total) return true;

            if(i != 0 && curr % target == 0)
                return self(0, curr, self);
    
            for(int j = i; j < n; j++){
                if(vis[j] || nums[j] + (curr % target) > target) 
                    continue;
                vis[j] = 1;
                if(self(j + 1, curr + nums[j], self)) return true;
                vis[j] = 0;
            }
            return false;
        };
        return backtrack(0, 0, backtrack);
    }
};