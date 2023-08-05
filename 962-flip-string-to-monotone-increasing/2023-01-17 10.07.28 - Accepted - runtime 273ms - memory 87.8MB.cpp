class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<vector<int>> dp(s.size(), vector<int> (2, -1));
        auto solve = [&](int i, bool zeros, auto &&self){
            if(i >= s.size()) return 0;
            if(dp[i][zeros] != -1) return dp[i][zeros];
            if(zeros && s[i] == '0' || !zeros && s[i] == '1') return dp[i][zeros] = self(i + 1, zeros, self);
            if(zeros && s[i] == '1') return dp[i][zeros] = min(1 + self(i + 1, zeros, self), self(i + 1, !zeros, self));
            if(!zeros && s[i] == '0') return dp[i][zeros] = 1 + self(i + 1, zeros, self);
            return 0;
        };
        return solve(0, 1, solve);
    }
};