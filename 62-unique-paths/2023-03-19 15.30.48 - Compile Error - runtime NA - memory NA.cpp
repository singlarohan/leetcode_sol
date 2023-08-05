class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        auto solve = [&](int i, int j, auto &&self){
            if(i < 0 || j < 0 || i >= m || j >= n) return INT_MIN;
            if(dp[i][j] != -1) return dp[i][j];

        };

    }
};