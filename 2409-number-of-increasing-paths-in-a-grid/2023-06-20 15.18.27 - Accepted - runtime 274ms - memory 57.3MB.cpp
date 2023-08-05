class Solution {
private:
    int m, n;
    vector<vector<int>> dp;
    vector<int> r;
    vector<int> c;
    int M = 1e9 + 7;
public:
    int solve(int i, int j, vector<vector<int>> &grid){
        long long ans{};

        if(dp[i][j] != -1) return dp[i][j];

        for(int k = 0; k < 4; k++){
            int ni = i + r[k];
            int nj = j + c[k];
            if(ni >= 0 && ni < m && nj >= 0 && nj < n && grid[ni][nj] > grid[i][j])
                ans += 1 + solve(ni, nj, grid);
        }
        return dp[i][j] = ans % M;
    }

    int countPaths(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        dp = vector<vector<int>> (m, vector<int> (n, -1));
        r = {-1,0,0,1};
        c = {0,-1,1,0};
        long long ans{};
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                ans += 1 + solve(i, j, grid);
                ans %= M;
            }
        }
        return ans;
    }
};