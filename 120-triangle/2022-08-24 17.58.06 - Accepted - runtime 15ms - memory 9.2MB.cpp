class Solution {
public:
    int solve(int i, int j, vector<vector<int>> &dp, vector<vector<int>> & triangle){
        if(i >= triangle.size())
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        //go to j in next row
        int d = solve(i+1, j, dp,triangle);
        int dr = solve(i+1, j+1, dp,triangle);
        return dp[i][j] = triangle[i][j] + min(d, dr);
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int> (triangle[triangle.size() - 1].size(), -1));
        return solve(0, 0, dp, triangle);
    }
};