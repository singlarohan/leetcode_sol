class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp (high + 1, -1);
        auto solve = [&](int curr, auto &&self){
            if(curr > high) return 0;
            if(dp[curr] != -1) return dp[curr];
            int ans{};
            if(curr >= low && curr <= high) ans++;
            ans += self(curr + one, self);
            ans += self(curr + zero, self);
            return dp[curr] = ans;
        };
        return solve(0, solve);
    }
};