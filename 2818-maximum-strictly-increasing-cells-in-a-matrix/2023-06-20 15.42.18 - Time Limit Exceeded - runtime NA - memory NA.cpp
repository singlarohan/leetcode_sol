class Solution {
private:
    int m, n;
    vector<vector<int>> dp;
public:
    int solve(int i, int j, vector<vector<int>> &grid){
        int ans{};

        if(dp[i][j] != -1) return dp[i][j];
        //moving within the same row
        for(int k = 0; k < n; k++){
            if(grid[i][k] > grid[i][j])
                ans = max(ans, 1 + solve(i, k, grid));
        }
        for(int k = 0; k < m; k++){
            if(grid[k][j] > grid[i][j])
                ans = max(ans, 1 + solve(k, j, grid));
        }
        return dp[i][j] = ans;
    }

    int maxIncreasingCells(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        dp = vector<vector<int>> (m, vector<int> (n, -1));
        int ans{};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans = max(1 + solve(i, j, grid), ans);
            }
        }
        return ans;
    }
};