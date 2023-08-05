class Solution {
private:
    vector<vector<int>> dp;
    const int M = 1e9 + 7;
    int maxi;
public:
    int solve(int i, int n, int x){
        if(n == 0) return 1;

        if(n < 0 || i > maxi) return 0;

        if(dp[n][i] != -1) return dp[n][i];
        //nottake
        long long ans = solve(i + 1, n, x);
        //take
        ans += solve(i + 1, n - pow(i, x), x);

        return dp[n][i] = ans % M;
    }
    int numberOfWays(int n, int x) {
        maxi = pow(n, (double)1 / x) + 1;
        dp = vector<vector<int>> (n + 1, vector<int> (maxi + 1, -1));

        return solve(1, n, x);
    }
};