class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        auto solve = [&](int i, int j, auto &&self) -> int{
            if(i >= m || j >= n) return 1e9;
            if(i == m - 1 && j == n - 1) return grid[i][j];
            if(dp[i][j] != -1) return dp[i][j];
            return dp[i][j] = grid[i][j] + min(self(i + 1, j, self), self(i, j + 1, self));
        };
        return solve(0, 0, solve);
    }
};