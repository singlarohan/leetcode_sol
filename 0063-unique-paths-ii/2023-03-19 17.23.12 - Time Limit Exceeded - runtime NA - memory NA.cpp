class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& Grid) {
        int m = Grid.size(), n = Grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        auto solve = [&](int i, int j, auto &&self){
            if(i >= m || j >= n || Grid[i][j]) return 0;
            if(i == m - 1 && j == n - 1) return 1;
            if(dp[i][j] != -1) return dp[i][j];
            return self(i + 1, j, self) + self(i, j + 1, self);
        };
        return solve(0, 0, solve);
    }
};