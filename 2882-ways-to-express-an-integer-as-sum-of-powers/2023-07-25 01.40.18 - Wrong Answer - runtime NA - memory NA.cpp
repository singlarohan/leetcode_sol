class Solution {
private:
    vector<vector<int>> dp;
public:
    int solve(int i, int n, int x){
        if(n == 0) return 1;

        if(dp[n][i] != -1) return dp[n][i];

        int ans = 0;

        for(int j = i + 1; j <= pow(n, (double)1 / x); j++)
            ans += solve(j, n - pow(j, x), x);

        return dp[n][i] = ans;
    }
    int numberOfWays(int n, int x) {
        int maxi = pow(n, (double)1 / x);
        dp = vector<vector<int>> (n + 1, vector<int> (maxi + 1, -1));

        return solve(0, n, x);
    }
};