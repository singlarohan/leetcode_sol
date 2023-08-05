class Solution {
private:    
    int m, n;
    vector<vector<int>> dp;
    vector<int> r;
    vector<int> c;
public:
    int solve(int i, int j, vector<vector<int>> &grid){
        int ans{};

        if(dp[i][j] != -1) return dp[i][j];

        for(int k = 0; k < 4; k++){
            int ni = i + r[k];
            int nj = j + c[k];
            if(ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] > grid[i][j])
                ans = max(1 + solve(ni, nj, grid), ans);
        }
        return dp[i][j] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        dp = vector<vector<int>> (m, vector<int> (n, -1));
        r = {-1,0,0,1};
        c = {0,-1,1,0};
        int ans{};
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                ans = max(ans, 1 + solve(i, j, grid));
        return ans;
    }
};