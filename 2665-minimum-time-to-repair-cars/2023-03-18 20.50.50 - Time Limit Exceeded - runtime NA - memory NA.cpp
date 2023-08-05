class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        vector<vector<long long>> dp(ranks.size(), vector<long long> (cars + 1, -1));
        auto solve = [&](int i, int rem, auto &&self) -> long long{
            if(rem == 0) return 0;
            if(i >= ranks.size()) return INT_MAX;
            if(dp[i][rem] != -1) return dp[i][rem];
            long long ans = LLONG_MAX;
            for(int k = 0; k <= rem; k++)
                ans = min(ans, max((long long)k * k * ranks[i], self(i + 1, rem - k, self)));
            return dp[i][rem] = ans;
        };
        return solve(0, cars, solve);
    }
};