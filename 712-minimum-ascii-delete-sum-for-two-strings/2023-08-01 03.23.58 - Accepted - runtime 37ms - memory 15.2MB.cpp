class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();

        vector<vector<int>> dp(m + 1, vector<int> (n + 1, 0));

        int maxi = 0;

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = s1[i - 1] + dp[i - 1][j - 1];
                }
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

                maxi = max(maxi, dp[i][j]);
            }
        }
        int ans = -(2 * maxi);

        for(auto c:s1) ans += c;
        for(auto c:s2) ans += c;

        return ans;
    }
};