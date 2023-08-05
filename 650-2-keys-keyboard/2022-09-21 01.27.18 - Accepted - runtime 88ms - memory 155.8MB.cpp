class Solution {
public:
    vector<vector<int>> dp;
    
    int solve(int curr, int copd, int n){
        if(n == curr)
            return 0;
        if(curr > n)
            return INT_MAX - 1000;
        if(dp[curr][copd] != -1)
            return dp[curr][copd];
        int copy, paste;
        copy = paste = 0;
        //if copy and then paste
        copy = 2 + solve(curr + curr, curr, n);
        paste = 1 + solve(curr + copd, copd, n);
        return dp[curr][copd] = min(copy, paste);
        
    }
    int minSteps(int n) {
        dp = vector<vector<int>> (n+1, vector<int> (n+1, -1));
        if(n == 1)
            return 0;
        return 1 + solve(1, 1, n);
    }
};