class Solution {
public:
    vector<vector<int>> dp;
    int solve(int i , int j, vector<int> &points, int k){
        if(i + j == k)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = max(points[i] + solve(i + 1, j, points, k), points[points.size() - j - 1] + solve(i, j + 1, points, k));
    }
    int maxScore(vector<int>& cardPoints, int k) {
        dp = vector<vector<int>> (k + 1, vector<int> (k + 1, -1));
        return solve(0, 0, cardPoints, k);
    }
};