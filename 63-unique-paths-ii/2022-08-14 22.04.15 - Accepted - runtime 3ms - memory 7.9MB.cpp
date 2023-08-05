class Solution {
public:
    int solve(int m, int n, vector<vector<int>> &obs, vector<vector<int>> &dp){
        if(m < 0 || n < 0)
            return 0;
        if(m == 0 && n == 0){
            if(obs[m][n])
                return 0;
            return 1;
        }

        if(obs[m][n] == 1)
            return 0;
        if(dp[m][n] != -1)
            return dp[m][n];
        int l = solve(m - 1, n, obs, dp);
        int r = solve(m, n-1, obs, dp);
        return dp[m][n] = l + r;
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& obsGrid) {
        int m = obsGrid.size(), n = obsGrid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return solve(m-1, n-1, obsGrid, dp);
    }
};