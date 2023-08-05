class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp (high + 1, -1);
        int M = 1e9 + 7;
        auto solve = [&](int curr, auto &&self){
            if(curr > high) return 0;
            if(dp[curr] != -1) return dp[curr];
            long long ans{};
            if(curr >= low && curr <= high) ans++;
            ans += self(curr + one, self);
            ans += self(curr + zero, self);
            return dp[curr] = ans % M;
        };
        return solve(0, solve);
    }
};