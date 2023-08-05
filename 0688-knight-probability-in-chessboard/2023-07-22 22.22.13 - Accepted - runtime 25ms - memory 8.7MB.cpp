class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>> (n, vector<double> (k + 1, 2.0)));
        auto solve = [&](int i, int j, int rem, auto &&self) -> double{
            if(i < 0 || j < 0 || i >= n || j >= n)
            return 0;
            if(rem == 0)
            return 1;
            if(dp[i][j][rem] != (double)2)
            return dp[i][j][rem];
            double ans = 0;
            ans += self(i + 1, j - 2, rem - 1, self);
            ans += self(i + 1, j + 2, rem - 1, self);
            ans += self(i + 2, j - 1, rem - 1, self);
            ans += self(i + 2, j + 1, rem - 1, self);
            ans += self(i - 1, j - 2, rem - 1, self);
            ans += self(i - 1, j + 2, rem - 1, self);
            ans += self(i - 2, j - 1, rem - 1, self);
            ans += self(i - 2, j + 1, rem - 1, self);
            return dp[i][j][rem] = (ans/8);
        };
        return solve(row, column, k, solve);
    }
};