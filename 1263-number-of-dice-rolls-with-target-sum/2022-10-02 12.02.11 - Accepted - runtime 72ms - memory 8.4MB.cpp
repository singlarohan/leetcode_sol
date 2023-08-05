class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int M = 1e9 + 7;
        vector<vector<int>> dp(n+1, vector<int> (target + 1, -1));
        auto solve = [&](int k, int n, int target, auto &&self){
            if(target < 0)
                return 0;
            if(n == 0 && target == 0)
                return 1;
            if(n == 0)
            return 0;
            if(dp[n][target] != -1)
            return dp[n][target];
            long long ans{};
            for(int i = 1; i <= k; i++)
                ans = (ans + self(k, n - 1, target - i, self)) % M;
            return dp[n][target] = (int)ans;
        };
        return solve(k, n, target, solve);

    }
};