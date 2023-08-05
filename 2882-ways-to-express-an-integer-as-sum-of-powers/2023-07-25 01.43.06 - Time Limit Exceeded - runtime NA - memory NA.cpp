class Solution {
private:
    vector<vector<int>> dp;
    const int M = 1e9 + 7;
public:
    int solve(int i, int n, int x){
        if(n == 0) return 1;

        if(dp[n][i] != -1) return dp[n][i];

        long long ans = 0;

        for(int j = i + 1; pow(j, x) <= n; j++)
            ans += solve(j, n - pow(j, x), x);

        return dp[n][i] = ans % M;
    }
    int numberOfWays(int n, int x) {
        int maxi = pow(n, (double)1 / x);
        dp = vector<vector<int>> (n + 1, vector<int> (maxi + 1, -1));

        return solve(0, n, x);
    }
};