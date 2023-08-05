class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.size(), n = text2.size();
        // vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        // auto solve = [&](int i, int j, auto &&self){
        //     if(i >= m || j >= n) return 0;
        //     if(dp[i][j] != -1) return dp[i][j];
        //     if(text1[i] == text2[j]) return dp[i][j] = 1 + self(i + 1, j + 1, self);
        //     return dp[i][j] = max(self(i + 1, j, self), self(i, j + 1, self));
        // };
        // return solve(0, 0, solve);
        //Tabulation
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        // for(int i = 0; i <= n; i++) dp[m][i] = 0;
        //already zero
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(text1[i] == text2[j]) dp[i][j] = 1 + dp[i + 1][j + 1];
                else dp[i][j] = max(dp[i+1][j], dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }
};