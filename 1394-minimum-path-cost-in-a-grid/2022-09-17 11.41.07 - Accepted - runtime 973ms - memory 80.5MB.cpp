class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& Cost){
        if(i == grid.size() - 1)
            return grid[i][j];
        if(dp[i][j] != INT_MAX)
            return dp[i][j];
        for(int k = 0; k < grid[0].size(); k++)
            dp[i][j] = min(dp[i][j], grid[i][j] + Cost[grid[i][j]][k] + solve(i+1, k, grid, Cost));
        return dp[i][j];
    }
    
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        dp = vector<vector<int>> (grid.size(), vector<int> (grid[0].size(), INT_MAX));
        int ans{INT_MAX};
        for(int j = 0; j < grid[0].size(); j++)
            ans = min(ans, solve(0, j, grid, moveCost));
        return ans;
    }
};