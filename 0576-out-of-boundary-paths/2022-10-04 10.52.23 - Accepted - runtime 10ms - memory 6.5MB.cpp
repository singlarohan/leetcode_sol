class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int M = 1e9 + 7;
        int dp[50][50][51];
        memset(dp, -1, sizeof(dp));
        auto solve = [&](int i, int j, int rem, auto &&self) -> long long{
            if(i < 0 || j < 0 || i >= m || j >= n)
            return 1;
            if(rem == 0)
            return 0;
            if(dp[i][j][rem] != -1)
            return dp[i][j][rem];
            long long ans{};
            ans += self(i + 1, j, rem - 1, self);
            ans += self(i - 1, j, rem - 1, self);
            ans += self(i, j + 1, rem - 1, self);
            ans += self(i, j - 1, rem - 1, self);
            return dp[i][j][rem] = ans % M;
        };
        return solve(startRow, startColumn, maxMove, solve) % M;
    }
};