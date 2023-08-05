class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        auto solve = [&](int i, int j, auto &&self){
            if(dp[i][j] != -1) return dp[i][j];
            int ans{};
            if(i - 1 >= 0 && j + 1 < n && grid[i][j] < grid[i - 1][j + 1]) 
                ans = 1 + self(i - 1, j + 1, self);
            if(i >= 0 && j + 1 < n && grid[i][j] < grid[i][j + 1]) 
                ans = max(ans, 1 + self(i, j + 1, self));
            if(i + 1 < m && j + 1 < n && grid[i][j] < grid[i + 1][j + 1]) 
                ans = max(ans, 1 + self(i + 1, j + 1, self));
            return dp[i][j] = ans;
        };
        int as{};
        for(int i = 0; i < m; i++)
            as = max(as, solve(i,0,solve));
        return as;
    }
};