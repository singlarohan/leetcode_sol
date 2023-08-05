class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i, int j, vector<vector<int>> &mat){
        if(mat[i][j] == -1 || i >= mat.size() || j >= mat[0].size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        int up, down, left, right;
        up = down = left = right = 0;
        int temp = mat[i][j];
        mat[i][j] = -1;
        if(i != 0 && mat[i-1][j] > temp)
            up = 1 + solve(i-1, j, mat);

        if(i != mat.size() - 1 && (mat[i+1][j] > temp))
            down = 1 + solve(i+1, j, mat);
            
        if(j != 0 && mat[i][j-1] > temp)
            left = 1 + solve(i, j - 1, mat);
        
        if(j != mat[0].size() - 1 && mat[i][j+1] > temp)
            right = 1 + solve(i, j+1, mat);
        
        mat[i][j] = temp;
        
        return dp[i][j] = max(left, max(right, max(up, down)));
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        dp = vector<vector<int>> (matrix.size(), vector<int> (matrix[0].size(), -1));
        int ans{};
        for(int i = 0; i < matrix.size(); i++)
            for(int j = 0; j < matrix[0].size(); j++)
                ans = max(ans, 1 + solve(i, j, matrix));
        
        return ans;
    }
};