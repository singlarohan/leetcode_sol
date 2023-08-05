class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int> (n, -1));
        // auto solve = [&](int i, int j, auto &&self) -> int{
        //     if(i >= m || j >= n) return 1e9;
        //     if(i == m - 1 && j == n - 1) return grid[i][j];
        //     if(dp[i][j] != -1) return dp[i][j];
        //     return dp[i][j] = grid[i][j] + min(self(i + 1, j, self), self(i, j + 1, self));
        // };
        // return solve(0, 0, solve);
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));
        dp[m - 1][n - 1] = grid[m - 1][n - 1];
        for(int i = 0; i < m; i++) dp[i][n] = 1e9;
        for(int j = 0; j < n; j++) dp[m][j] = 1e9;
        for(int i = m - 1; i>= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(!(i == m - 1 && j == n - 1))
                dp[i][j] = grid[i][j] + min(dp[i+1][j], dp[i][j + 1]);
            }
        }
        return dp[0][0];
    }
};