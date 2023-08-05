class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        auto solve = [&](int i, int j, auto &&self){
            if(i == m - 1 && j == n - 1) return 1;
            if(i < 0 || j < 0 || i >= m || j >= n) return 0;
            if(dp[i][j] != -1) return dp[i][j];
            return dp[i][j] = self(i + 1, j, self) + self(i, j + 1, self);
        };
        return solve(0, 0, solve);
    }
};