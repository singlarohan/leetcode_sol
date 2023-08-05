class Solution {
public:
    long long mostPoints(vector<vector<int>>& ques) {
        int n = ques.size();
        vector<long long> dp(n + 1, 0);
        for(int i = n - 1; i >= 0; i--){
            long long ans = ques[i][0];

            if(i + ques[i][1] + 1 < n) ans += dp[i + ques[i][1] + 1];
            
            dp[i] = max(ans, dp[i + 1]);
        }
        return dp[0];
    }
};