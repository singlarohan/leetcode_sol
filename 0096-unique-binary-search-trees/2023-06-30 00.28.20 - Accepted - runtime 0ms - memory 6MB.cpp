class Solution {
private:
    vector<int> dp;
public:
    int solve(int n){
        if(n == 0 || n == 1) return 1;

        if(dp[n] != -1) return dp[n];
        
        int ans{};

        for(int i = 1; i <= n; i++){
            //placing ith element in the center;
            ans += solve(i - 1) * solve(n - i);
        }
        return dp[n] = ans;
    }
    int numTrees(int n) {
        dp = vector<int> (n + 1, -1);
        return solve(n);
    }
};