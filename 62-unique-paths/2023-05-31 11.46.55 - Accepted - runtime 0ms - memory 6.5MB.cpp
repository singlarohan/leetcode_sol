class Solution {
public:
    vector<vector<int>> dp;
    int x,y;
    int solve(int i, int j){
        if(i >= x || j >= y) return 0;
        if(i == x - 1 && j == y - 1) return 1;
        if(dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = solve(i + 1, j) + solve(i, j + 1);
    }

    int uniquePaths(int m, int n) {
        dp = vector<vector<int>> (m + 1, vector<int> (n +1, -1));
        dp[m - 1][n - 1] = 1;
        for(int i = 0; i < m + 1; i++) dp[i][n] = 0;
        for(int i = 0; i < n + 1; i++) dp[m][i] = 0;

        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(!(i == m - 1 && j == n - 1))
                dp[i][j] = dp[i + 1][ j] + dp[i][j + 1];
            }
        }
        return dp[0][0];
    }
};