class Solution {
public:
    // vector<vector<int>> dp;
    int solve(int i , int j, vector<int> &points, int k){
        if(k == 0)
            return 0;
        if(dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = max(points[i] + solve(i + 1, j, points, k - 1), points[points.size() - j - 1] + solve(i, j + 1, points, k - 1));
    }

    int maxScore(vector<int>& cardPoints, int k) {
        //WITH DP
        // dp = vector<vector<int>> (k + 1, vector<int> (k + 1, -1));
        // return solve(0, 0, cardPoints, k);
        //Sliding window
        int sum{};
        for(int i = 0; i < cardPoints.size() - k; i++)
            sum += cardPoints[i];
        int mini = sum;
        int total = sum;
        for(int i = 0; i < k; i++){
            sum = sum - cardPoints[i] + cardPoints[i+ cardPoints.size() - k];
            total += cardPoints[i+ cardPoints.size() - k];
            mini = min(mini, sum);
        }
        return total - mini;
    }
};