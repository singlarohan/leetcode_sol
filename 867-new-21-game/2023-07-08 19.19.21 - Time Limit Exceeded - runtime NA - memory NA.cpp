class Solution {
private:
    int maxi;
    vector<double> dp;
public:
    double solve(int n, int k){
        if(k <= 0) return 1.0;
        
        if(dp[n] != -1.0) return dp[n];
        double curr = 0;
        for(int i = 1; i <= maxi; i++)
            if(i <= n) curr += (1.0/maxi) * solve(n - i, k - i);

        return dp[n] = curr;
    }
    double new21Game(int n, int k, int maxPts) {
        dp = vector<double> (n + 1, -1.0);
        maxi = maxPts;
        return solve(n, k);
    }
};