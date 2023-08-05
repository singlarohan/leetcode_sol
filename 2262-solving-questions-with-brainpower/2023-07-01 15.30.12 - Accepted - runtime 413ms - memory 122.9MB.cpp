class Solution {
public:
    long long mostPoints(vector<vector<int>>& ques) {
        int n = ques.size();
        vector<long long> dp(n + 1, -1);
        auto solve = [&](int i, auto &&self) -> long long{
            if(i >= n) return 0;
            if(dp[i] != -1) return dp[i];
            //if take
            long long ans = ques[i][0] + self(i + ques[i][1] + 1, self);
            //if not take
            ans = max(ans, self(i + 1, self));
            return dp[i] = ans;
        };
        return solve(0, solve);
        for(int i = n - 1; i >= 0; i--){
            long long ans = ques[i][0];
            
            if(i + ques[i][1] + 1 < n) ans = dp[i + ques[i][1] + 1];
            
            dp[i] = max(ans, dp[i + 1]);
        }
        return dp[0];
    }
};