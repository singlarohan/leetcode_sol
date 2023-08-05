class Solution {
public:
    // int solve(int i, int j, string &s, string &t){
    //     if(j >= t.size())
    //         return 1;
    //     if(i >= s.size())
    //         return 0;
    //     if(dp[i][j] != -1)
    //         return dp[i][j];
    //     int ans = solve(i+1, j, s, t);
    //     if(s[i] == t[j])
    //         ans += solve(i+1, j+1, s, t);
    //     return dp[i][j] = ans;
    // }

    int numDistinct(string s, string t) {
        while(s.size() && t.back() != s.back())
            s.pop_back();
        if(s == t)
            return 1;
        int m = s.size();
        int n = t.size();
        vector<vector<long long>> dp(m + 1, vector<long long> (n + 1, 0));
        for(int i = 0; i < m + 1; i++) dp[i][n] = 1;
        for(int i = 0; i < n; i++) dp[m][i] = 0;
        for(int i = m - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                long long ans = dp[i+1][j];
                if(s[i] == t[j])
                    ans += dp[i+1][j+1];
                dp[i][j] = ans;
            }
        }
        return dp[0][0];
    }
};