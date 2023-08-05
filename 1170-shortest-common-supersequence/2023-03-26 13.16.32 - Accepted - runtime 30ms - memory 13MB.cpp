class Solution {
public:
    string shortestCommonSupersequence(string word1, string word2) {
        // m + n - len(lcs)
        int n = word1.size(), m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, 0));
        int maxi{};
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = 1 + dp[i-1][j - 1];
                    maxi = max(maxi, dp[i][j]);
                }
                else dp[i][j] = max(dp[i][j - 1], dp[i-1][j]);
            }
            // prev = dp;
        }
        string s;
        int i = n, j = m;
        while(i > 0 && j > 0){
            if(word1[i - 1] == word2[j - 1]){
                s += word1[i - 1];
                i--, j--;
            }
            else if(dp[i][j - 1] > dp[i - 1][j]){
                s += word2[j - 1];
                j--;
            }
            else{
                s += word1[i - 1];
                i--;
            }
        }
        while(i > 0) s += word1[i - 1], i--;
        while(j > 0) s += word2[j - 1], j--;
        reverse(s.begin(), s.end());
        return s;
        // return n + m - maxi;
    }
};