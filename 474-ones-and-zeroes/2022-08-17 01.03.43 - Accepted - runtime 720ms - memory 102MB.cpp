class Solution {
public:
    int solve(int m, int n, vector<string>& strs, vector<vector<vector<int>>> &dp, int i){
        if(m < 0 || n < 0)
            return INT_MIN;
        if(i >= strs.size()){
            if(m >= 0 && n >= 0)
            return 0;
            else
            return INT_MIN;
        }
        if(dp[i][m][n] != -1)
            return dp[i][m][n];
        int zcnt{}, ocnt{};
        for(int j = 0; j<strs[i].size(); j++){
            if(strs[i][j] == '0')
                zcnt++;
            else
                ocnt++;
        }
        int choose = 1 + solve(m - zcnt, n - ocnt, strs, dp, i+1);
        int notchoose = solve(m, n, strs, dp, i+1);
        return dp[i][m][n] = max(choose, notchoose);
    }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<vector<int>>> dp(strs.size(), vector<vector<int>> (m+1, vector<int> (n+1, -1)));
        int ans = solve(m,n,strs,dp,0);
        if(ans < 0)
            return 0;
        else
            return ans;
    }
};