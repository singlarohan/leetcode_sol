class Solution {
public:
    int dp[100][100];
    
    int solve(int i, int j, vector<vector<int>> &mat){
        if(i ==  mat.size() - 1)
            return mat[i][j];
        if(dp[i][j] != -1)
            return dp[i][j];
        int ld, d, rd;
        ld = d = rd = INT_MAX - 1000;
        if(j)
            ld = solve(i+1, j-1, mat);
        d = solve(i+1, j, mat);
        if(j != mat[0].size() - 1)
            rd = solve(i+1, j+1, mat);
        return dp[i][j] = mat[i][j] + min(ld, min(d, rd));
        
    }
    
    int minFallingPathSum(vector<vector<int>>& matrix) {
        memset(dp, -1, sizeof(dp));
        int ans{INT_MAX};
        for(int i = 0; i < matrix[0].size(); i++)
            ans = min(ans, solve(0, i, matrix));
        return ans;
    }
};