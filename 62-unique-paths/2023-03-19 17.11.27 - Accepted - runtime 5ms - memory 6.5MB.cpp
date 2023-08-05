class Solution {
public:
    int uniquePaths(int m, int n) {
        // vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        // auto solve = [&](int i, int j, auto &&self){
        //     if(i == m - 1 && j == n - 1) return 1;
        //     if(i < 0 || j < 0 || i >= m || j >= n) return 0;
        //     if(dp[i][j] != -1) return dp[i][j];

        // };
        // return solve(0, 0, solve);
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        dp[m - 1][n - 1] = 1;
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(!(i == m - 1 && j == n - 1))
                dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};