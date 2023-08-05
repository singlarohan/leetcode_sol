class Solution {
public:
    int solve(long long int n, unordered_map<long long int, int> &dp){
        if(n == 1)
            return 0;
        if(dp[n] != 0)
            return dp[n];
        if(n % 2 == 0)
            return dp[n] = 1 + solve(n/2, dp);
        else
            return dp[n] = 1 + min(solve(n-1, dp), solve(n+1, dp));
        
    }
    
    int integerReplacement(int n) {
        // int count{0};
        // while(n != 1){
        //     if(n % 2 == 0)
        //         n = n/2;
        //     else
        //         n = n - 1;
        //     count++;
        // }
        // return count;
        // vector<int> dp(n+2, -1);
        unordered_map<long long int, int> dp;
        // dp[INT_MAX] = 32;
        return solve((long long int)n, dp);
    }
};