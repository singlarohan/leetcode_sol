class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(), 
        vector<vector<int>> (grid[0].size(), vector<int> (grid[0].size(), 0)));
        auto solve = [&](int i, int j, int k, auto &&self){
            if(j < 0 || k < 0 || j >= grid[0].size() || k >= grid[0].size())
                return INT_MIN;
            if(i == grid.size()) return 0;
            if(dp[i][j][k] != 0) return dp[i][j][k];
            int ans{INT_MIN};
            for(int x = 0; x < 3; x++)
                for(int y = 0; y < 3; y++)
                    ans = max(ans, self(i + 1, j + x - 1, k + y - 1, self)) ;
            ans += grid[i][j];
            if(j != k) ans += grid[i][k];
            return dp[i][j][k] = ans;
        };
        return solve(0, 0, grid[0].size() - 1, solve);
    }
};